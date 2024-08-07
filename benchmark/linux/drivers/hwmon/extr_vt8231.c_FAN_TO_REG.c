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

/* Variables and functions */
 int /*<<< orphan*/  clamp_val (int,int,int) ; 

__attribute__((used)) static inline u8 FAN_TO_REG(long rpm, int div)
{
	if (rpm <= 0 || rpm > 1310720)
		return 0;
	return clamp_val(1310720 / (rpm * div), 1, 255);
}