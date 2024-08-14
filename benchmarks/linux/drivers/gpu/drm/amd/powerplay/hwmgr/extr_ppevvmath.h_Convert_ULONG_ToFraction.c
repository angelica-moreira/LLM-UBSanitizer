#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct TYPE_3__ {int full; } ;
typedef  TYPE_1__ fInt ;

/* Variables and functions */
 int MAX ; 
 int SHIFT_AMOUNT ; 

__attribute__((used)) static fInt Convert_ULONG_ToFraction(uint32_t X)
{
	fInt temp;

	if (X <= MAX)
		temp.full = (X << SHIFT_AMOUNT);
	else
		temp.full = 0;

	return temp;
}