#ifndef _BACH_128BIT_H_
#define _BACH_128BIT_H_

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

#ifdef C74_X64

#ifdef BACH_USE_NATIVE_128BIT_INTEGER
typedef __int128_t t_int128;
#else
class t_int128 
{
private:
	union {
		struct {
			t_uint64 i_lo;
			union {
				t_int64 i_hi;
				t_uint64 i_uhi;
			};
		};
		struct {
			t_uint32 i_a;
			t_uint32 i_b;
			t_uint32 i_c;
			t_uint32 i_d;
		};
		t_uint32 i_vec[4];
	};

public:
	t_int128(void);
	t_int128(const t_int32 l);	
	t_int128(const t_uint32 l);
	t_int128(const t_int64 l);
	t_int128(const t_uint64 l);	
	t_int128(const t_uint32 vec[], int count = 4);	
	t_int128(std::string s, int radix = 10);
	
	t_int128 & operator+=(const t_int128 &b);	
	t_int128 operator-(void) const;	
	t_int128 & operator-=(const t_int128 &b);	
	t_int128 & operator<<=(const int sh);	
	t_int128 & operator>>=(const int sh);
	t_int128 & operator*=(const t_int128 &b);
	
	t_int128 & operator&=(const t_int128 &b);	
	t_int128 & operator|=(const t_int128 &b);	
	t_int128 & operator/=(t_int128 b);	
	t_int128 & operator%=(t_int128 b);	
	t_int128 operator++(void);	
	t_int128 operator--(void);
	
	bool operator==(const t_int128 &b) const;	
	bool operator!=(const t_int128 &b) const;	
	bool operator>(const t_int128 &b) const;	
	bool operator<(const t_int128 &b) const;	
	bool operator>=(const t_int128 &b) const;	
	bool operator<=(const t_int128 &b) const;	
	
	const t_int128 operator+(const t_int128 &b) const;	
	const t_int128 operator*(const t_int128 &b) const;	
	const t_int128 operator-(const t_int128 &b) const;	
	const t_int128 operator/(t_int128 b) const;
	const t_int128 operator/(t_int64 b) const;
	const t_int128 operator/(t_int32 b) const;
	const t_int128 operator%(t_int128 b) const;	
	const t_int128 operator%(t_int64 b) const;	
	const t_int128 operator%(t_int32 b) const;	
	const t_int128 operator|(const t_int128 &b) const;	
	const t_int128 operator&(const t_int128 &b) const;	
	const t_int128 operator<<(const int &b) const;	
	const t_int128 operator>>(const int &b) const;
	
    explicit operator t_int64() const;
    explicit operator t_uint64() const;
    
	friend const t_int128 operator+(const t_int64 &a, const t_int128 &b);
	friend const t_int128 operator*(const t_int64 &a, const t_int128 &b);
	friend const t_int128 operator-(const t_int64 &a, const t_int128 &b);
	friend const t_int128 operator/(const t_int64 &a, const t_int128 &b);
	friend const t_int128 operator/(const t_int32 &a, const t_int128 &b);
	friend const t_int128 operator%(const t_int64 &a, const t_int128 &b);
	friend const t_int128 operator%(const t_int32 &a, const t_int128 &b);
	friend const t_int128 operator|(const t_int64 &a, const t_int128 &b);
	friend const t_int128 operator&(const t_int64 &a, const t_int128 &b);
	friend const bool operator>(const t_int64 &a, const t_int128 &b);
	friend const bool operator<(const t_int64 &a, const t_int128 &b);
	friend const bool operator>=(const t_int64 &a, const t_int128 &b);
	friend const bool operator<=(const t_int64 &a, const t_int128 &b);

	bool isSmall() const;
	t_uint64 getLo(void) const;
	
	
	operator std::string() const;
	
	
	t_int128 div_128_128(t_int128 b, t_int128 *r) const;	
	t_int128 pow_128_128(const unsigned int &b);
	const std::string toString(unsigned int radix) const;

};
#endif // BACH_USE_NATIVE_128BIT_INTEGER

#endif // C74_X64
#endif // _BACH_128BIT_H_
