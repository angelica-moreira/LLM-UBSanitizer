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
 int B43_CCK_RATE_11MB ; 
 int B43_CCK_RATE_1MB ; 
 int B43_CCK_RATE_2MB ; 
 int B43_CCK_RATE_5MB ; 

__attribute__((used)) static inline int b43_is_cck_rate(int rate)
{
	return (rate == B43_CCK_RATE_1MB ||
		rate == B43_CCK_RATE_2MB ||
		rate == B43_CCK_RATE_5MB || rate == B43_CCK_RATE_11MB);
}