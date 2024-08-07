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
struct pcmcia_device {struct local_info* priv; } ;
struct local_info {int /*<<< orphan*/  eth_dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  netif_device_detach (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int atmel_suspend(struct pcmcia_device *link)
{
	struct local_info *local = link->priv;

	netif_device_detach(local->eth_dev);

	return 0;
}