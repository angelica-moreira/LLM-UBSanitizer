#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;

/* Variables and functions */
 int GETU32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PUTU32 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ROUND (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int TE41 (int) ; 
 int TE42 (int) ; 
 int TE43 (int) ; 
 int TE44 (int) ; 
 int /*<<< orphan*/  s ; 
 int /*<<< orphan*/  t ; 

__attribute__((used)) static void rijndaelEncrypt(u32 rk[/*44*/], u8 pt[16], u8 ct[16])
{
	u32 s0, s1, s2, s3, t0, t1, t2, t3;
	int Nr = 10;
	int r;

	/*
	 * map byte array block to cipher state
	 * and add initial round key:
	 */
	s0 = GETU32(pt) ^ rk[0];
	s1 = GETU32(pt +  4) ^ rk[1];
	s2 = GETU32(pt +  8) ^ rk[2];
	s3 = GETU32(pt + 12) ^ rk[3];

#define ROUND(i, d, s) \
d##0 = TE0(s##0) ^ TE1(s##1) ^ TE2(s##2) ^ TE3(s##3) ^ rk[4 * i]; \
d##1 = TE0(s##1) ^ TE1(s##2) ^ TE2(s##3) ^ TE3(s##0) ^ rk[4 * i + 1]; \
d##2 = TE0(s##2) ^ TE1(s##3) ^ TE2(s##0) ^ TE3(s##1) ^ rk[4 * i + 2]; \
d##3 = TE0(s##3) ^ TE1(s##0) ^ TE2(s##1) ^ TE3(s##2) ^ rk[4 * i + 3]

	/* Nr - 1 full rounds: */
	r = Nr >> 1;
	for (;;) {
		ROUND(1, t, s);
		rk += 8;
		if (--r == 0)
			break;
		ROUND(0, s, t);
	}

#undef ROUND

	/*
	 * apply last round and
	 * map cipher state to byte array block:
	 */
	s0 = TE41(t0) ^ TE42(t1) ^ TE43(t2) ^ TE44(t3) ^ rk[0];
	PUTU32(ct, s0);
	s1 = TE41(t1) ^ TE42(t2) ^ TE43(t3) ^ TE44(t0) ^ rk[1];
	PUTU32(ct +  4, s1);
	s2 = TE41(t2) ^ TE42(t3) ^ TE43(t0) ^ TE44(t1) ^ rk[2];
	PUTU32(ct +  8, s2);
	s3 = TE41(t3) ^ TE42(t0) ^ TE43(t1) ^ TE44(t2) ^ rk[3];
	PUTU32(ct + 12, s3);
}