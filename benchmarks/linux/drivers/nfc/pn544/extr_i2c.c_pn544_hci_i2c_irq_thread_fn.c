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
struct sk_buff {int dummy; } ;
struct pn544_i2c_phy {int hard_fault; scalar_t__ run_mode; int /*<<< orphan*/  hdev; int /*<<< orphan*/  fw_work; int /*<<< orphan*/  fw_cmd_result; struct i2c_client* i2c_dev; } ;
struct i2c_client {int irq; int /*<<< orphan*/  dev; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int EBADMSG ; 
 int ENOMEM ; 
 int EREMOTEIO ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ PN544_FW_MODE ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  nfc_hci_recv_frame (int /*<<< orphan*/ ,struct sk_buff*) ; 
 int /*<<< orphan*/  pn544_hci_i2c_fw_read_status (struct pn544_i2c_phy*) ; 
 int pn544_hci_i2c_read (struct pn544_i2c_phy*,struct sk_buff**) ; 
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 

__attribute__((used)) static irqreturn_t pn544_hci_i2c_irq_thread_fn(int irq, void *phy_id)
{
	struct pn544_i2c_phy *phy = phy_id;
	struct i2c_client *client;
	struct sk_buff *skb = NULL;
	int r;

	if (!phy || irq != phy->i2c_dev->irq) {
		WARN_ON_ONCE(1);
		return IRQ_NONE;
	}

	client = phy->i2c_dev;
	dev_dbg(&client->dev, "IRQ\n");

	if (phy->hard_fault != 0)
		return IRQ_HANDLED;

	if (phy->run_mode == PN544_FW_MODE) {
		phy->fw_cmd_result = pn544_hci_i2c_fw_read_status(phy);
		schedule_work(&phy->fw_work);
	} else {
		r = pn544_hci_i2c_read(phy, &skb);
		if (r == -EREMOTEIO) {
			phy->hard_fault = r;

			nfc_hci_recv_frame(phy->hdev, NULL);

			return IRQ_HANDLED;
		} else if ((r == -ENOMEM) || (r == -EBADMSG)) {
			return IRQ_HANDLED;
		}

		nfc_hci_recv_frame(phy->hdev, skb);
	}
	return IRQ_HANDLED;
}