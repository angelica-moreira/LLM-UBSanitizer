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
 int /*<<< orphan*/  memcpy (unsigned int*,unsigned char*,int) ; 

__attribute__((used)) static inline int tep_is_bigendian(void)
{
	unsigned char str[] = { 0x1, 0x2, 0x3, 0x4 };
	unsigned int val;

	memcpy(&val, str, 4);
	return val == 0x01020304;
}