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

/* Variables and functions */
 int /*<<< orphan*/  F (int) ; 

__attribute__((used)) static void
invala_gr (int regno)
{
#	define F(reg)	case reg: ia64_invala_gr(reg); break

	switch (regno) {
		F(  0); F(  1); F(  2); F(  3); F(  4); F(  5); F(  6); F(  7);
		F(  8); F(  9); F( 10); F( 11); F( 12); F( 13); F( 14); F( 15);
		F( 16); F( 17); F( 18); F( 19); F( 20); F( 21); F( 22); F( 23);
		F( 24); F( 25); F( 26); F( 27); F( 28); F( 29); F( 30); F( 31);
		F( 32); F( 33); F( 34); F( 35); F( 36); F( 37); F( 38); F( 39);
		F( 40); F( 41); F( 42); F( 43); F( 44); F( 45); F( 46); F( 47);
		F( 48); F( 49); F( 50); F( 51); F( 52); F( 53); F( 54); F( 55);
		F( 56); F( 57); F( 58); F( 59); F( 60); F( 61); F( 62); F( 63);
		F( 64); F( 65); F( 66); F( 67); F( 68); F( 69); F( 70); F( 71);
		F( 72); F( 73); F( 74); F( 75); F( 76); F( 77); F( 78); F( 79);
		F( 80); F( 81); F( 82); F( 83); F( 84); F( 85); F( 86); F( 87);
		F( 88); F( 89); F( 90); F( 91); F( 92); F( 93); F( 94); F( 95);
		F( 96); F( 97); F( 98); F( 99); F(100); F(101); F(102); F(103);
		F(104); F(105); F(106); F(107); F(108); F(109); F(110); F(111);
		F(112); F(113); F(114); F(115); F(116); F(117); F(118); F(119);
		F(120); F(121); F(122); F(123); F(124); F(125); F(126); F(127);
	}
#	undef F
}