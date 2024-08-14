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
struct pcmcia_device {struct cm4000_dev* priv; } ;
struct cm4000_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  stop_monitor (struct cm4000_dev*) ; 

__attribute__((used)) static int cm4000_suspend(struct pcmcia_device *link)
{
	struct cm4000_dev *dev;

	dev = link->priv;
	stop_monitor(dev);

	return 0;
}