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
struct net_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  lowpan_rx_exit () ; 
 int /*<<< orphan*/  open_count ; 

__attribute__((used)) static int lowpan_stop(struct net_device *dev)
{
	open_count--;
	if (!open_count)
		lowpan_rx_exit();
	return 0;
}