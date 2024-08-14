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
struct pcmcia_device {struct ipw_dev* priv; } ;
struct ipw_dev {int /*<<< orphan*/  hardware; struct pcmcia_device* link; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int config_ipwireless (struct ipw_dev*) ; 
 int /*<<< orphan*/  ipwireless_detach (struct pcmcia_device*) ; 
 int /*<<< orphan*/  ipwireless_hardware_create () ; 
 int /*<<< orphan*/  kfree (struct ipw_dev*) ; 
 struct ipw_dev* kzalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ipwireless_attach(struct pcmcia_device *link)
{
	struct ipw_dev *ipw;
	int ret;

	ipw = kzalloc(sizeof(struct ipw_dev), GFP_KERNEL);
	if (!ipw)
		return -ENOMEM;

	ipw->link = link;
	link->priv = ipw;

	ipw->hardware = ipwireless_hardware_create();
	if (!ipw->hardware) {
		kfree(ipw);
		return -ENOMEM;
	}
	/* RegisterClient will call config_ipwireless */

	ret = config_ipwireless(ipw);

	if (ret != 0) {
		ipwireless_detach(link);
		return ret;
	}

	return 0;
}