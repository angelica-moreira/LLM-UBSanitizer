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
struct pcmcia_device {scalar_t__ open; struct local_info* priv; } ;
struct local_info {int /*<<< orphan*/  eth_dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  netif_device_attach (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  reset_airo_card (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int airo_resume(struct pcmcia_device *link)
{
	struct local_info *local = link->priv;

	if (link->open) {
		reset_airo_card(local->eth_dev);
		netif_device_attach(local->eth_dev);
	}

	return 0;
}