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
typedef  int u64 ;

/* Variables and functions */
 int div_u64 (int,int) ; 

__attribute__((used)) static inline u64 div_factor_fine(u64 num, int factor)
{
	if (factor == 100)
		return num;
	num *= factor;
	return div_u64(num, 100);
}