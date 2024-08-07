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
typedef  int /*<<< orphan*/  u_int ;
struct net_device {int /*<<< orphan*/  base_addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  COM20020_REG_W_COMMAND ; 
 int /*<<< orphan*/  arcnet_outb (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void com20020_command(struct net_device *dev, int cmd)
{
	u_int ioaddr = dev->base_addr;

	arcnet_outb(cmd, ioaddr, COM20020_REG_W_COMMAND);
}