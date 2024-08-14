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
typedef  int /*<<< orphan*/  phy_interface_t ;

/* Variables and functions */
 int /*<<< orphan*/  PHY_INTERFACE_MODE_NA ; 
 int /*<<< orphan*/  PHY_INTERFACE_MODE_XAUI ; 

phy_interface_t mv88e6390x_port_max_speed_mode(int port)
{
	if (port == 9 || port == 10)
		return PHY_INTERFACE_MODE_XAUI;

	return PHY_INTERFACE_MODE_NA;
}