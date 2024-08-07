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
struct ipw_network {int dummy; } ;
struct ipw_hardware {struct ipw_network* network; } ;

/* Variables and functions */

void ipwireless_associate_network(struct ipw_hardware *hw,
				  struct ipw_network *network)
{
	hw->network = network;
}