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
struct phy_device {int dummy; } ;
struct fixed_phy_status {int dummy; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 struct phy_device* __fixed_phy_register (unsigned int,struct fixed_phy_status*,struct device_node*,int /*<<< orphan*/ *) ; 

struct phy_device *fixed_phy_register(unsigned int irq,
				      struct fixed_phy_status *status,
				      struct device_node *np)
{
	return __fixed_phy_register(irq, status, np, NULL);
}