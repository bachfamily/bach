/*
 *  bach_rat.hpp
 *
 * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License
 * as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef bach_rat_h
#define bach_rat_h

#include <type_traits>
#include "bach_urrat.hpp"



template <typename U> struct TwiceAsBigInt {
    typedef U data;
};

#ifdef C74_X64
template <> struct TwiceAsBigInt<t_int64> {
    typedef t_int128 data;
};
#endif

template <> struct TwiceAsBigInt<t_int32> {
    typedef t_int64 data;
};

template <> struct TwiceAsBigInt<t_int16> {
    typedef t_int32 data;
};



template <typename U, typename V> struct TwiceAsBigInt2 {
    typedef U data;
};

#ifdef C74_X64
template <> struct TwiceAsBigInt2<t_int64, t_int64> {
    typedef t_int128 data;
};

template <typename U> struct TwiceAsBigInt2<t_int64, U> {
    typedef t_int128 data;
};

template <typename U> struct TwiceAsBigInt2<U, t_int64> {
    typedef t_int128 data;
};
#endif

template <> struct TwiceAsBigInt2<t_int32, t_int32> {
    typedef t_int32 data;
};

template <> struct TwiceAsBigInt2<t_int16, t_int32> {
    typedef t_int64 data;
};

template <> struct TwiceAsBigInt2<t_int32, t_int16> {
    typedef t_int64 data;
};

template <> struct TwiceAsBigInt2<t_int16, t_int16> {
    typedef t_int32 data;
};





template <typename T>
class t_rat : public t_urrat<T>
{
private:
    
public:
    template <typename Type2> t_rat(const t_urrat<Type2> &u) : t_urrat<T>(u)
    {
        reduce();
    }
    t_rat() = default;
    t_rat(const T num, const T den);
    
    template <typename Type2> explicit t_rat(const Type2 &l): t_urrat<T>(l) { reduce(); }
    
    T reduce(void) {
        return t_rat<T>::reduce(this->r_num, this->r_den);
    } // returns the signed gcd
    
    inline void set(T n) { t_rat<T>::r_num = n; t_rat<T>::r_den = 1; };
    inline void set(T n, T d) { t_rat<T>::r_num = n; t_rat<T>::r_den = d; reduce(); };

    t_rat & gcd(const t_rat &b) const;
    t_rat & abs(void) const;
    t_rat inv(void) const { return t_rat<T>(t_rat<T>::r_den, t_rat<T>::r_num); }

    const bool isInteger(void) const { return t_rat<T>::r_den == 1; }

    
    t_rat operator-(void) const { return t_rat<T>(-t_rat<T>::r_num, t_rat<T>::r_den); }
    

    t_rat & operator+=(const t_rat &b);
    t_rat & operator-=(const t_rat &b);
    t_rat & operator*=(const t_rat &b);
    t_rat & operator/=(const t_rat &b);
    t_rat & operator%=(t_rat b);

    template <typename U> t_rat & operator+=(const U b) {
        t_rat<T>::r_num += t_rat<T>::r_den * b;
        return *this;
    }

    template <typename U> t_rat & operator-=(U b) {
        t_rat<T>::r_num -= t_rat<T>::r_den * b;
        return *this;
    }
    
    template <typename U> t_rat & operator*=(U b) {
        t_atom_long up = b;
        t_atom_long dn = t_rat<T>::r_den;
        t_rat<t_atom_long>::reduce(up, dn);
        t_rat<T>::r_num *= static_cast<T>(up);
        t_rat<T>::r_den = static_cast<T>(dn);
        return *this;
    }

    template <typename U> t_rat & operator/=(U b) {
        t_atom_long up = t_rat<T>::r_num;
        t_atom_long dn = b;
        t_rat<t_atom_long>::reduce(up, dn);
        t_rat<T>::r_num = static_cast<T>(up);
        t_rat<T>::r_den *= static_cast<T>(dn);
        return *this;
    }
    
    template <typename U> t_rat & operator%=(U b) {
        t_rat<T>::r_num %= t_rat<T>::r_den * b;
        return *this;
    }
    
    t_rat operator++(void) { return t_rat(*this) += 1; };
    t_rat operator--(void) { return t_rat(*this) -= 1; };
    
    const t_rat operator+(const t_rat &b) const { return t_rat(*this) += b; }
    const t_rat operator*(const t_rat &b) const { return t_rat(*this) *= b; }
    const t_rat operator-(const t_rat &b) const { return t_rat(*this) -= b; }
    const t_rat operator/(const t_rat &b) const { return t_rat(*this) /= b; }
    const t_rat operator%(t_rat b) const;
    
    template <typename U> const t_rat operator+(const U b) const { return t_rat(*this) += b; };
    template <typename U> const t_rat operator*(const U b) const { return t_rat(*this) *= b; };
    template <typename U> const t_rat operator-(const U b) const { return t_rat(*this) -= b; };
    template <typename U> const t_rat operator/(const U b) const { return t_rat(*this) /= b; };

    // all the inequality operators are always false in case of invalid rationals (with denominator 0)
    const bool operator==(const t_rat &b) const;
    const bool operator!=(const t_rat &b) const;
    const bool operator<(const t_rat &b) const;
    const bool operator<=(const t_rat &b) const;
    const bool operator>(const t_rat &b) const;
    const bool operator>=(const t_rat &b) const;
    
    
    template <typename U> const bool operator==(const U &b) const { return isInteger() && b == t_rat<T>::r_num; }
    template <typename U> const bool operator!=(const U &b) const { return !isInteger() || b != t_rat<T>::r_num; }
    
    template <typename U> const bool operator<(const U b) const
    {
        typename TwiceAsBigInt2<T, U>::data t = t_rat<T>::r_den * b;
        return t_rat<T>::r_num < t;
    }
    
    template <typename U> const bool operator>(const U b) const
    {
        typename TwiceAsBigInt2<T, U>::data t = t_rat<T>::r_den * b;
        return t_rat<T>::r_num > t;
    }
    
    template <typename U> const bool operator<=(const U b) const
    {
        typename TwiceAsBigInt2<T, U>::data t = t_rat<T>::r_den * b;
        return t_rat<T>::r_num <= t;
    }
    
    template <typename U> const bool operator>=(const U b) const
    {
        typename TwiceAsBigInt2<T, U>::data t = t_rat<T>::r_den * b;
        return t_rat<T>::r_num >= t;
    }
    
    template <typename U> friend const t_rat operator+(const U a, const t_rat &b) { return b + a; }
    template <typename U> friend const t_rat operator*(const U a, const t_rat &b) { return b * a; }
    template <typename U> friend const t_rat operator-(const U a, const t_rat &b) { return -b + a; }
    template <typename U> friend const t_rat operator/(const U a, const t_rat &b) { return a * b.inv(); }
    template <typename U> friend const t_rat operator%(const U a, t_rat b) {
        t_rat<T> div;
        b = b.abs();
        div = a / b;
        return a - (b * (div.num() / div.den()));
    }

    template <typename U> friend const bool operator==(const U a, const t_rat &b) { return b == a; }
    template <typename U> friend const bool operator!=(const U a, const t_rat &b) { return b != a; }
    template <typename U> friend const bool operator<(const U a, const t_rat &b) { return b > a; }
    template <typename U> friend const bool operator<=(const U a, const t_rat &b) { return b >= a; }
    template <typename U> friend const bool operator>(const U a, const t_rat &b) { return b < a; }
    template <typename U> friend const bool operator>=(const U a, const t_rat &b) { return b >= a; }
    

    static T reduce(T &num, T &den);
    static T gcd(T a, T b);
    static T lcm(T a, T b);
    
    static double cmpEpsilon;

};

template <typename T>
double t_rat<T>::cmpEpsilon = 0.001;

template <typename T>
t_rat<T>::t_rat(const T num, const T den) : t_urrat<T>(num, den)
{
    reduce();
}

template <typename T>
T t_rat<T>::reduce(T &num, T &den)
{
    typename TwiceAsBigInt<T>::data l_num, l_den;
    T m, temp, a = 1, b;
    
    if (den == 0 && num == 0)
        return 0; // nothing to do, in this case (0/0 is a "normal" form, even if it's not a mathematically-valid rational...)
    
    if (den == 0) {
        num = num > 0 ? 1 : -1;
        return 0;
    }
    if (num == 0) {
        den = 1;
        return 0;
    }
    
    l_num = num;
    l_den = den;
    
    if (l_num != 1 && l_den != 1) { // if any of them is 1, we are done.
        a = static_cast<T>(l_num);
        b = static_cast<T>(l_den);
        
        if (b > a) {
            temp = a;
            a = b;
            b = temp;
        }
        
        while (b != 0) {
            m = a % b;
            a = b;
            b = m;
        }
        
        // now a contains the gcd!
        
        l_num /= a;
        l_den /= a;
    }
    
    if (l_den < 0) {
        l_den *= -1;
        l_num *= -1;
        a *= -1;
    }
    
    num = static_cast<T>(l_num);
    den = static_cast<T>(l_den);
    return static_cast<T>(a);
}

template <typename T>
T t_rat<T>::gcd(T a, T b)
{
    T temp, m, a1, b1;
    a1 = a;	b1 = b;
    
    if (b1 > a1) {
        temp = a1;
        a1 = b1;
        b1 = temp;
    }
    
    while (b1) {
        m = a1 % b1;
        a1 = b1;
        b1 = m;
    }
    
    return a1;
}

template <typename T>
T t_rat<T>::lcm(T a, T b)
{
    return  static_cast<TwiceAsBigInt<T> >(a) *
            static_cast<TwiceAsBigInt<T> >(b) /
            static_cast<TwiceAsBigInt<T> >(gcd(a, b));
    
 //   return (((TwiceAsBigInt<T>) a) * ((TwiceAsBigInt<T>) b) / (TwiceAsBigInt<T>) gcd(a,b));
}

template <typename T>
t_rat<T> & t_rat<T>::gcd(const t_rat<T> &b) const
{
    return t_rat<T>(
                    gcd(t_rat<T>::num, b.num()),
                    lcm(t_rat<T>::r_den, b.den()));
}

template <typename T>
t_rat<T> & t_rat<T>::abs(void) const
{
    if (*t_rat<T>::num >= 0)
        return *this;
    else
        return -*this;
}

template <typename T>
t_rat<T> & t_rat<T>::operator+=(const t_rat<T> &b)
{
    T den1 = t_rat<T>::r_den, den2 = b.den();
    T gcd = reduce(den1, den2);
    
    if (gcd > 0) { // new way, working best with big numbers
        *this = t_rat<T> (t_rat<T>::r_num * den2 + den1 * b.num(),
                        den1 * den2 * gcd);
    } else { // something wrong with the fractions. Let's stick with the old way, working badly with big numbers
        *this = t_rat<T> (t_rat<T>::r_num * b.den() + t_rat<T>::r_den * b.num(),
                        t_rat<T>::r_den * b.den());
    }
    
    return *this;
}

/*
template <typename T>
const t_rat<T> t_rat<T>::operator+=(t_int32 b)
{
    t_rat<T>::r_num += b * t_rat<T>::r_den;
    return *this;
}
*/

template <typename T>
t_rat<T> & t_rat<T>::operator-=(const t_rat<T> &b)
{
    return *this += -b;
}

template <typename T>
t_rat<T> & t_rat<T>::operator*=(const t_rat<T> &b)
{
    t_rat<T> x (t_rat<T>::r_num, b.den());
    t_rat<T> y (b.num(), t_rat<T>::r_den);
    *this = t_rat<T> (x.num() * y.num(),
                      x.den() * y.den());
    return *this;
}

template <typename T>
t_rat<T> & t_rat<T>::operator/=(const t_rat<T> &b)
{
    return *this *= b.inv();
}

template <typename T>
t_rat<T> & t_rat<T>::operator%=(t_rat<T> b)
{
    t_rat<T> div;
    b = b.abs();
    div = *this / b;
    *this -= (b * (div.num() / div.den()));
    return *this;
}

template <typename T, typename Type2>
const t_rat<T> operator+(const Type2 &a, const t_rat<T> &b)
{
    return b + a;
}

template <typename T>
const t_rat<T> t_rat<T>::operator%(t_rat b) const
{
    return t_rat(*this) %= b;
}


template <typename T>
const bool t_rat<T>::operator==(const t_rat &b) const
{
    return t_rat<T>::r_den == b.den() && t_rat<T>::r_num == b.num();
}

template <typename T>
const bool t_rat<T>::operator!=(const t_rat &b) const
{
    return t_rat<T>::r_den != b.den() || t_rat<T>::r_num != b.num();
}

template <typename T>
const bool t_rat<T>::operator<(const t_rat &b) const
{
    typename TwiceAsBigInt<T>::data x, y;
    if (t_rat<T>::r_den == 0 || b.den() == 0)
        return false;
    x = static_cast<typename TwiceAsBigInt<T>::data >(t_rat<T>::r_num) *
        static_cast<typename TwiceAsBigInt<T>::data >(b.den());
    y = static_cast<typename TwiceAsBigInt<T>::data >(t_rat<T>::r_den) *
        static_cast<typename TwiceAsBigInt<T>::data >(b.num());
    if (x < y)
        return true;
    else
        return false;
}

template <typename T>
const bool t_rat<T>::operator<=(const t_rat &b) const
{
    typename TwiceAsBigInt<T>::data x, y;
    if (t_rat<T>::r_den == 0 || b.den() == 0)
        return false;
    x = static_cast<typename TwiceAsBigInt<T>::data >(t_rat<T>::r_num) *
    static_cast<typename TwiceAsBigInt<T>::data >(b.den());
    y = static_cast<typename TwiceAsBigInt<T>::data >(t_rat<T>::r_den) *
    static_cast<typename TwiceAsBigInt<T>::data >(b.num());
    if (x <= y)
        return true;
    else
        return false;
}

template <typename T>
const bool t_rat<T>::operator>(const t_rat &b) const
{
    typename TwiceAsBigInt<T>::data x, y;
    if (t_rat<T>::r_den == 0 || b.den() == 0)
        return false;
    x = static_cast<typename TwiceAsBigInt<T>::data >(t_rat<T>::r_num) *
    static_cast<typename TwiceAsBigInt<T>::data >(b.den());
    y = static_cast<typename TwiceAsBigInt<T>::data >(t_rat<T>::r_den) *
    static_cast<typename TwiceAsBigInt<T>::data >(b.num());
    if (x > y)
        return true;
    else
        return false;
}

template <typename T>
const bool t_rat<T>::operator>=(const t_rat &b) const
{
    typename TwiceAsBigInt<T>::data x, y;
    if (t_rat<T>::r_den == 0 || b.den() == 0)
        return false;
    x = static_cast<typename TwiceAsBigInt<T>::data >(t_rat<T>::r_num) *
    static_cast<typename TwiceAsBigInt<T>::data >(b.den());
    y = static_cast<typename TwiceAsBigInt<T>::data >(t_rat<T>::r_den) *
    static_cast<typename TwiceAsBigInt<T>::data >(b.num());
    if (x >= y)
        return true;
    else
        return false;
}


/*
 template <typename T>
 const t_urrat<T> operator+(const t_int8 &a, const t_urrat<T> &b)
 {
 return b + a;
 }
 
 template <typename T>
 const t_urrat<T> operator+(const t_uint8 &a, const t_urrat<T> &b)
 {
 return b + a;
 }
 
 template <typename T>
 const t_urrat<T> operator+(const t_int16 &a, const t_urrat<T> &b)
 {
 return b + a;
 }
 
 template <typename T>
 const t_urrat<T> operator+(const t_uint16 &a, const t_urrat<T> &b)
 {
 return b + a;
 }
 
 template <typename T>
 const t_urrat<T> operator+(const t_int32 &a, const t_urrat<T> &b)
 {
 return b + a;
 }
 
 template <typename T>
 const t_urrat<T> operator+(const t_uint32 &a, const t_urrat<T> &b)
 {
 return b + a;
 }

template <typename T>
const t_urrat<T> operator+(const t_int64 &a, const t_urrat<T> &b)
{
    return b + a;
}

template <typename T>
const t_urrat<T> operator+(const t_uint64 &a, const t_urrat<T> &b)
{
    return b + a;
}
*/

#endif /* bach_rat_h */
