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
typedef  int /*<<< orphan*/  u32 ;
struct skge_port {int /*<<< orphan*/  msg_enable; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 struct skge_port* netdev_priv (struct net_device*) ; 

__attribute__((used)) static void skge_set_msglevel(struct net_device *netdev, u32 value)
{
	struct skge_port *skge = netdev_priv(netdev);
	skge->msg_enable = value;
}