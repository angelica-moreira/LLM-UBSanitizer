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
struct gic_kvm_info {int dummy; } ;

/* Variables and functions */
 struct gic_kvm_info const* gic_kvm_info ; 

const struct gic_kvm_info *gic_get_kvm_info(void)
{
	return gic_kvm_info;
}