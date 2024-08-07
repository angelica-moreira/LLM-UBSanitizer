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
 int /*<<< orphan*/  r_dtr (unsigned short) ; 
 int /*<<< orphan*/  w_ctr (unsigned short,int) ; 

__attribute__((used)) static int imm_byte_in(unsigned short base, char *buffer, int len)
{
	int i;

	/*
	 * The following is based on documented timing signals
	 */
	w_ctr(base, 0x4);
	for (i = len; i; i--) {
		w_ctr(base, 0x26);
		*buffer++ = r_dtr(base);
		w_ctr(base, 0x25);
	}
	return 1;		/* All went well - we hope! */
}