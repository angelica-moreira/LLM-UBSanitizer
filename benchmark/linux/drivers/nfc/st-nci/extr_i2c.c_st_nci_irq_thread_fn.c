#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct st_nci_i2c_phy {TYPE_1__* ndlc; struct i2c_client* i2c_dev; } ;
struct sk_buff {int dummy; } ;
struct i2c_client {int irq; int /*<<< orphan*/  dev; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {int /*<<< orphan*/  powered; scalar_t__ hard_fault; } ;

/* Variables and functions */
 int EBADMSG ; 
 int ENOMEM ; 
 int EREMOTEIO ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  ndlc_recv (TYPE_1__*,struct sk_buff*) ; 
 int /*<<< orphan*/  st_nci_i2c_disable (struct st_nci_i2c_phy*) ; 
 int st_nci_i2c_read (struct st_nci_i2c_phy*,struct sk_buff**) ; 

__attribute__((used)) static irqreturn_t st_nci_irq_thread_fn(int irq, void *phy_id)
{
	struct st_nci_i2c_phy *phy = phy_id;
	struct i2c_client *client;
	struct sk_buff *skb = NULL;
	int r;

	if (!phy || !phy->ndlc || irq != phy->i2c_dev->irq) {
		WARN_ON_ONCE(1);
		return IRQ_NONE;
	}

	client = phy->i2c_dev;
	dev_dbg(&client->dev, "IRQ\n");

	if (phy->ndlc->hard_fault)
		return IRQ_HANDLED;

	if (!phy->ndlc->powered) {
		st_nci_i2c_disable(phy);
		return IRQ_HANDLED;
	}

	r = st_nci_i2c_read(phy, &skb);
	if (r == -EREMOTEIO || r == -ENOMEM || r == -EBADMSG)
		return IRQ_HANDLED;

	ndlc_recv(phy->ndlc, skb);

	return IRQ_HANDLED;
}