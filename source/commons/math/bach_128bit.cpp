/*
 *  bach_128bit.cpp
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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


#include "math/bach_128bit.h"

#ifdef C74_X64
#ifndef BACH_USE_NATIVE_128BIT_INTEGER

t_int128::t_int128(void) 
{
}

t_int128::t_int128(const t_int32 l) 
{
    *this = t_int128((const t_int64) l);
}    

t_int128::t_int128(const t_uint32 l) 
{
    *this = t_int128((const t_int64) l);
}    

t_int128::t_int128(const t_int64 l) 
{
    if (l >= 0) {
        i_hi = 0;
        i_lo = l;
    } else {
        i_uhi = 0xffffffffffffffffLL;
        i_lo = *(reinterpret_cast<t_uint64 *> (const_cast<t_int64 *>(&l)));
    }
}

t_int128::t_int128(const t_uint64 l) 
{
    i_hi = 0;
    i_lo = l;
}

t_int128::t_int128(const t_uint32 vec[], int count) 
{
    i_uhi = i_lo = 0; 
    memcpy(i_vec, vec, count * sizeof(t_uint32));
}

t_int128::t_int128(std::string s, int radix) 
{
    std::string::iterator it;
    *this = 0;
    t_int128 positional = 1;
    for (it = s.end() - 1; it >= s.begin(); --it) {
        char ch = *it;
        int digit;
        if (ch >= '0' && ch <= '9')
            digit = ch - '0';
        else if (ch >= 'A' && ch <= 'Z')
            digit = ch - 'A' + 10;
        else if (ch >= 'a' && ch <= 'z')
            digit = ch - 'a' + 10;
        else
            continue;
        if (digit >= radix)
            continue;
        *this += digit * positional;
        positional *= radix;
    }
}

t_int128 & t_int128::operator+=(const t_int128 &b) 
{
    if (0xffffffffffffffffLL - i_lo >= b.i_lo)
        i_hi += b.i_hi;
    else
        i_hi += b.i_hi + 1;
    i_lo = i_lo + b.i_lo;
    return *this;
}

t_int128 t_int128::operator-(void) const
{
    t_int128 r;
    r.i_lo = ~i_lo;
    r.i_uhi = ~i_uhi;
    return r + 1;
}

t_int128 & t_int128::operator-=(const t_int128 &b) 
{
    *this += -b;
    return *this;
}

t_int128 & t_int128::operator<<=(const int sh) 
{
    if (sh >= 128) {
        i_lo = i_uhi = 0;
    } else if (sh >= 64) {
        i_uhi = i_lo << (sh - 64);
        i_lo = 0;
    } else if (sh > 0) {
        i_uhi = (i_uhi << sh) | (i_lo >> (64 - sh));
        i_lo = i_lo << sh;
    } 
    return *this;
}

t_int128 & t_int128::operator>>=(const int sh) 
{
    if (sh >= 128) {
        i_lo = i_uhi = i_hi >= 0 ? 0 : -1;
    } else if (sh >= 64) {
        i_lo = i_hi >> (sh - 64);
        i_hi = i_hi >= 0 ? 0 : -1;
    } else if (sh > 0) {
        i_lo = (i_lo >> sh) | (i_hi << (64 - sh));
        i_hi = i_hi >> sh;
    }
    return *this;
}

t_int128 & t_int128::operator*=(const t_int128 &b) 
{
    t_uint64 ab = static_cast<t_uint64> (i_a) * b.i_a;
    t_uint64 bc = static_cast<t_uint64> (i_a) * b.i_b + static_cast<t_uint64> (i_b) * b.i_a;
    t_uint64 cd = static_cast<t_uint64> (i_a) * b.i_c + static_cast<t_uint64> (i_b) * b.i_b + static_cast<t_uint64> (i_c) * b.i_a;
    t_uint64 d_ = static_cast<t_uint64> (i_a) * b.i_d + static_cast<t_uint64> (i_b) * b.i_c + static_cast<t_uint64> (i_c) * b.i_b + static_cast<t_uint64> (i_d) * b.i_a;
    i_lo = ab + (bc << 32);
    i_hi = (bc >> 32) + cd + (d_ << 32);
    return *this;
}

bool t_int128::operator==(const t_int128 &b) const
{
    return i_hi == b.i_hi && i_lo == b.i_lo;
}

bool t_int128::operator!=(const t_int128 &b) const
{
    return i_hi != b.i_hi || i_lo != b.i_lo;
}

bool t_int128::operator>(const t_int128 &b) const
{
    if (i_hi == b.i_hi)
        return i_lo > b.i_lo;
    else
        return i_hi > b.i_hi;
}

bool t_int128::operator<(const t_int128 &b) const
{
    if (i_hi == b.i_hi)
        return i_lo < b.i_lo;
    else
        return i_hi < b.i_hi;
}

bool t_int128::operator>=(const t_int128 &b) const
{
    return !(*this < b);
}

bool t_int128::operator<=(const t_int128 &b) const
{
    return !(*this > b);
}

t_int128 & t_int128::operator&=(const t_int128 &b) 
{
    i_uhi = i_uhi & b.i_uhi;
    i_lo = i_lo & b.i_lo;
    return *this;
}

t_int128 & t_int128::operator|=(const t_int128 &b) 
{
    i_uhi = i_uhi | b.i_uhi;
    i_lo = i_lo | b.i_lo;
    return *this;
}

t_int128 & t_int128::operator/=(t_int128 b) 
{
    if (isSmall() && b.isSmall())
        return *this = getLo() / b.getLo();
    else
        return *this = div_128_128(b, NULL);
}

t_int128 & t_int128::operator%=(t_int128 b) 
{
    if (isSmall() && b.isSmall())
        return *this = getLo() % b.getLo();
    else {
        div_128_128(b, this);
        return *this;
    }
}

t_int128 t_int128::operator++(void) 
{
    return *this += 1;
}

t_int128 t_int128::operator--(void) 
{
    return *this -= 1;
}

const t_int128 t_int128::operator+(const t_int128 &b) const
{
    return t_int128(*this) += b;
}

const t_int128 t_int128::operator*(const t_int128 &b) const
{
    return t_int128(*this) *= b;
}

const t_int128 t_int128::operator-(const t_int128 &b) const
{
    return t_int128(*this) -= b;
}

const t_int128 t_int128::operator/(t_int128 b) const
{
    if (isSmall() && b.isSmall())
        return getLo() / b.getLo();
    else
        return div_128_128(b, NULL);
}

const t_int128 t_int128::operator%(t_int128 b) const
{
    if (isSmall() && b.isSmall())
        return getLo() % b.getLo();
    else {
        t_int128 r = *this;
        div_128_128(b, &r);
        return r;
    }
}

const t_int128 t_int128::operator/(t_int64 b) const
{
    if (isSmall())
        return getLo() / b;
    else
        return div_128_128(b, NULL);
}

const t_int128 t_int128::operator%(t_int64 b) const
{
    if (isSmall())
        return getLo() % b;
    else {
        t_int128 r = *this;
        div_128_128(b, &r);
        return r;
    }
}

const t_int128 t_int128::operator/(t_int32 b) const
{
    if (isSmall())
        return getLo() / b;
    else
        return div_128_128(b, NULL);
}

const t_int128 t_int128::operator%(t_int32 b) const
{
    if (isSmall())
        return getLo() % b;
    else {
        t_int128 r = *this;
        div_128_128(b, &r);
        return r;
    }
}

const t_int128 t_int128::operator|(const t_int128 &b) const
{
    return t_int128(*this) |= b;
}

const t_int128 t_int128::operator&(const t_int128 &b) const
{
    return t_int128(*this) &= b;
}

const t_int128 t_int128::operator<<(const int &b) const
{
    return t_int128(*this) <<= b;
}


const t_int128 t_int128::operator>>(const int &b) const
{
    return t_int128(*this) >>= b;
}

t_int128 t_int128::div_128_128(t_int128 b, t_int128 *r) const
{
    t_int128 res, rem;
    int sign = 1;
    t_int128 a = *this;
    if (i_hi < 0) {
        a = -a;
        sign = -1;
    }
    if (b.i_hi < 0) {
        b = -b;
        sign *= -1;
    }

    res = rem = 0;
    
    int i;
    for (i = 63; i >= 0; --i) {
        rem <<= 1;
        rem.i_lo |= ((a.i_hi & ((t_uint64) 1 << i)) != 0);
        if (rem >= b) {
            rem -= b;
            res.i_hi |= (t_uint64) 1 << i;
        }
    }
    for (i = 63; i >= 0; --i) {
        rem <<= 1;
        rem.i_lo |= ((a.i_lo & ((t_uint64) 1 << i)) != 0);

        if (rem >= b) {
            rem -= b;
            res.i_lo |= (t_uint64) 1 << i;
        }
    }
    
    res *= sign;
    if (r)
        *r = rem * sign;
    return res;
}

t_int128 t_int128::pow_128_128(const unsigned int &b) 
{
    unsigned int i;
    if (b == 0)
        return 0;
    if (b == 1)
        return *this;
    t_int128 res = *this;
    for (i = 2; i * 2 <= b && i * 2 != 0; i *= 2) {
        res *= res;
    }
    
    for ( ; i < b; ++i) {
        res *= *this;
    }
    return res;
}

const t_int128 operator+(const t_int64 &a, const t_int128 &b)
{
    return b + a;
}

const t_int128 operator*(const t_int64 &a, const t_int128 &b)
{
    return b * a;
}

const t_int128 operator-(const t_int64 &a, const t_int128 &b)
{
    return t_int128(a) - b;
}

const t_int128 operator/(const t_int64 &a, const t_int128 &b)
{
    if (b.isSmall())
        return a / b;
    else
        return t_int128(a) / b;
}

const t_int128 operator%(const t_int64 &a, const t_int128 &b)
{
    if (b.isSmall())
        return a % b;
    else
        return t_int128(a) % b;
}

const t_int128 operator/(const t_int32 &a, const t_int128 &b)
{
    if (b.isSmall())
        return a / b;
    else
        return t_int128(a) / b;
}

const t_int128 operator%(const t_int32 &a, const t_int128 &b)
{
    if (b.isSmall())
        return a % b;
    else
        return t_int128(a) % b;
}

const t_int128 operator|(const t_int64 &a, const t_int128 &b)
{
    return b | a;
}

const t_int128 operator&(const t_int64 &a, const t_int128 &b)
{
    return b & a;
}

const bool operator>(const t_int64 &a, const t_int128 &b)
{
    return b < a;
}

const bool operator<(const t_int64 &a, const t_int128 &b)
{
    return b > a;
}

const bool operator>=(const t_int64 &a, const t_int128 &b)
{
    return b <= a;
}

const bool operator<=(const t_int64 &a, const t_int128 &b)
{
    return b >= a;
}

t_int128::operator t_int64() const
{
    return getLo();
}

t_int128::operator t_uint64() const
{
    return getLo();
}

t_uint64 t_int128::getLo(void) const
{
    return i_lo;
}

t_int128::operator std::string() const
{
    return toString(10);
}

const std::string t_int128::toString(unsigned int radix) const
{
    if (radix < 2 || radix > 36)
        return "";
    std::string s;
    t_int128 val = *this;
    do {
        t_int128 digit;
        char ch;
        val = val.div_128_128(radix, &digit);
        ch = digit.i_lo < 10 ? digit.i_lo + '0' : digit.i_lo - 10 + 'a';
        s = ch + s;
    } while (val != 0);
    return s;
}

bool t_int128::isSmall() const 
{
    return (i_lo > 0x7fffffffL && i_uhi == 0xffffffffL) || (i_uhi == 0);
}

#endif // BACH_USE_NATIVE_128BIT_INTEGER
#endif // C74_X64
