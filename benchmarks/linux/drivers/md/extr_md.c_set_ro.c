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
struct kernel_param {int dummy; } ;

/* Variables and functions */
 int kstrtouint (char const*,int,unsigned int*) ; 
 int /*<<< orphan*/  start_readonly ; 

__attribute__((used)) static int set_ro(const char *val, const struct kernel_param *kp)
{
	return kstrtouint(val, 10, (unsigned int *)&start_readonly);
}