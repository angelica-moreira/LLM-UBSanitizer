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
typedef  int u32 ;

/* Variables and functions */
 int host1x_uclass_wait_syncpt_indx_f (unsigned int) ; 
 int host1x_uclass_wait_syncpt_thresh_f (unsigned int) ; 

__attribute__((used)) static inline u32 host1x_class_host_wait_syncpt(
	unsigned indx, unsigned threshold)
{
	return host1x_uclass_wait_syncpt_indx_f(indx)
		| host1x_uclass_wait_syncpt_thresh_f(threshold);
}