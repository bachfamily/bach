//
//  bach_rat.hpp
//  bach
//
//  Created by Andrea Agostini on 21/07/17.
//
//

#ifndef bach_urrat_hpp
#define bach_urrat_hpp

#include "bach.h"

#ifdef BACH_MAX
#include "ext.h"
#endif

#ifdef BACH_JITCLANG
#include "bach_jitclang.h"
#endif

#include <string>

#ifndef BACH_MAX
typedef __int64_t t_int64;
typedef __uint64_t t_uint64;
typedef __int32_t t_int32;
typedef __uint32_t t_uint32;
#endif

template <typename T>
class t_rat;

template <typename T>
class t_urrat
{
private:
    
protected:

    
public:
    T r_num;
    T r_den;
    
    constexpr t_urrat() = default;
    
    constexpr t_urrat(const T num, const T den) : r_num(num), r_den(den) {}
    
    template <typename U> constexpr t_urrat(const U l) : r_num(l), r_den(1) {}
    
    constexpr t_urrat(const double d) : r_num(d * 1000), r_den(1000) {}
    
    operator double() const {
        if (r_den == 0)
            return r_num;
        return static_cast<double>(r_num) / static_cast<double>(r_den);
    }
    
    operator t_atom_long() const {
        if (r_den == 0)
            return r_num;
        return r_num / r_den;
    }

    template <typename Type2>
    t_urrat(const t_urrat<Type2> &u) { this->r_num = u.num(); this->r_den = u.den(); }
    
    template <typename Type2>
    t_urrat(const t_rat<Type2> &u) { this->r_num = u.num(); this->r_den = u.den(); }
    
    inline T num(void) const { return r_num; };
    inline T den(void) const { return r_den; };
    inline void set(T n) { r_num = n; r_den = 1; };
    inline void set(T n, T d) { r_num = n; r_den = d; };
    inline void setnum(T n) { r_num = n; };
    inline void setden(T d) { r_den = d; };
    
    t_urrat inv(void) const;
    t_urrat operator-(void) const;
    bool operator==(const t_urrat &b) const;
    bool operator!=(const t_urrat &b) const;
    
    std::string to_string() const {
        return std::to_string(r_num) + '/' + std::to_string(r_den);
    }
    
    static double defaultDen;
};

template <typename T>
double t_urrat<T>::defaultDen = 1000;

template <typename T>
t_urrat<T> t_urrat<T>::operator-(void) const
{
    return t_urrat<T>(-r_num, r_den);
}

template <typename T>
bool t_urrat<T>::operator==(const t_urrat &b) const
{
    return r_num == b.r_num && r_den == b.r_den;
}

template <typename T>
bool t_urrat<T>::operator!=(const t_urrat &b) const
{
    return !(*this == b);
}

template <typename T>
t_urrat<T> t_urrat<T>::inv(void) const
{
    return t_urrat<T>(r_den, r_num);
}


#endif /* bach_urrat_hpp */
