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
struct wb_domain {int dummy; } ;
struct dirty_throttle_control {int dummy; } ;

/* Variables and functions */
 struct wb_domain global_wb_domain ; 

__attribute__((used)) static struct wb_domain *dtc_dom(struct dirty_throttle_control *dtc)
{
	return &global_wb_domain;
}