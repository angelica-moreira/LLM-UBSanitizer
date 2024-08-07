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
struct net_device {int base_addr; int flags; } ;
struct arcnet_local {int setup; } ;

/* Variables and functions */
 int /*<<< orphan*/  COM20020_REG_W_XREG ; 
 int /*<<< orphan*/  D_NORMAL ; 
 int IFF_PROMISC ; 
 int IFF_UP ; 
 int PROMISCset ; 
 int /*<<< orphan*/  SUB_SETUP1 ; 
 int /*<<< orphan*/  arc_printk (int /*<<< orphan*/ ,struct net_device*,char*) ; 
 int /*<<< orphan*/  arcnet_outb (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  com20020_set_subaddress (struct arcnet_local*,int,int /*<<< orphan*/ ) ; 
 struct arcnet_local* netdev_priv (struct net_device*) ; 

__attribute__((used)) static void com20020_set_mc_list(struct net_device *dev)
{
	struct arcnet_local *lp = netdev_priv(dev);
	int ioaddr = dev->base_addr;

	if ((dev->flags & IFF_PROMISC) && (dev->flags & IFF_UP)) {
		/* Enable promiscuous mode */
		if (!(lp->setup & PROMISCset))
			arc_printk(D_NORMAL, dev, "Setting promiscuous flag...\n");
		com20020_set_subaddress(lp, ioaddr, SUB_SETUP1);
		lp->setup |= PROMISCset;
		arcnet_outb(lp->setup, ioaddr, COM20020_REG_W_XREG);
	} else {
		/* Disable promiscuous mode, use normal mode */
		if ((lp->setup & PROMISCset))
			arc_printk(D_NORMAL, dev, "Resetting promiscuous flag...\n");
		com20020_set_subaddress(lp, ioaddr, SUB_SETUP1);
		lp->setup &= ~PROMISCset;
		arcnet_outb(lp->setup, ioaddr, COM20020_REG_W_XREG);
	}
}