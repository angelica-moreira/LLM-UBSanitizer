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
 int str2hexnum (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline unsigned long str2hex(unsigned char *str)
{
	int value = 0;

	while (*str) {
		value = value << 4;
		value |= str2hexnum(*str++);
	}

	return value;
}