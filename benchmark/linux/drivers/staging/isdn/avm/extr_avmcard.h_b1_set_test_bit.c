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
typedef  enum avmcardtype { ____Placeholder_avmcardtype } avmcardtype ;

/* Variables and functions */
 int /*<<< orphan*/  B1_STAT0 (int) ; 
 int /*<<< orphan*/  b1_wr_reg (unsigned int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void b1_set_test_bit(unsigned int base,
				   enum avmcardtype cardtype,
				   int onoff)
{
	b1_wr_reg(base, B1_STAT0(cardtype), onoff ? 0x21 : 0x20);
}