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
typedef  int /*<<< orphan*/  umode_t ;
struct kobject {int dummy; } ;
struct attribute {int /*<<< orphan*/  mode; } ;

/* Variables and functions */
 int /*<<< orphan*/  X86_FEATURE_RTM ; 
 scalar_t__ boot_cpu_has (int /*<<< orphan*/ ) ; 

__attribute__((used)) static umode_t
tsx_is_visible(struct kobject *kobj, struct attribute *attr, int i)
{
	return boot_cpu_has(X86_FEATURE_RTM) ? attr->mode : 0;
}