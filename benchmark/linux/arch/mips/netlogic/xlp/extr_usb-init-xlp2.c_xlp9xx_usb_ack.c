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
typedef  int /*<<< orphan*/  u64 ;
struct irq_data {int irq; } ;

/* Variables and functions */
 int NLM_IRQS_PER_NODE ; 
#define  PIC_9XX_XHCI_0_IRQ 130 
#define  PIC_9XX_XHCI_1_IRQ 129 
#define  PIC_9XX_XHCI_2_IRQ 128 
 int /*<<< orphan*/  XLPII_USB3_INT_REG ; 
 int /*<<< orphan*/  nlm_write_usb_reg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nlm_xlpii_get_usb_regbase (int,int) ; 
 int /*<<< orphan*/  pr_err (char*,int,int) ; 

__attribute__((used)) static void xlp9xx_usb_ack(struct irq_data *data)
{
	u64 port_addr;
	int node, irq;

	/* Find the node and irq on the node */
	irq = data->irq % NLM_IRQS_PER_NODE;
	node = data->irq / NLM_IRQS_PER_NODE;

	switch (irq) {
	case PIC_9XX_XHCI_0_IRQ:
		port_addr = nlm_xlpii_get_usb_regbase(node, 1);
		break;
	case PIC_9XX_XHCI_1_IRQ:
		port_addr = nlm_xlpii_get_usb_regbase(node, 2);
		break;
	case PIC_9XX_XHCI_2_IRQ:
		port_addr = nlm_xlpii_get_usb_regbase(node, 3);
		break;
	default:
		pr_err("No matching USB irq %d node  %d!\n", irq, node);
		return;
	}
	nlm_write_usb_reg(port_addr, XLPII_USB3_INT_REG, 0xffffffff);
}