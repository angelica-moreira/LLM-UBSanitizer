#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct icom_port {unsigned char cable_id; int port; int /*<<< orphan*/  int_reg; TYPE_4__* global_reg; TYPE_3__* adapter; TYPE_1__* dram; } ;
struct TYPE_11__ {unsigned long processor_id; int /*<<< orphan*/ * global_int_mask; } ;
struct TYPE_10__ {int /*<<< orphan*/  int_mask_2; int /*<<< orphan*/  int_mask; } ;
struct TYPE_9__ {TYPE_2__* pci_dev; } ;
struct TYPE_8__ {int /*<<< orphan*/  dev; } ;
struct TYPE_7__ {int /*<<< orphan*/  cable_id; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_5__*) ; 
 int EIO ; 
 int ENODEV ; 
 unsigned char ICOM_CABLE_ID_MASK ; 
 unsigned char ICOM_CABLE_ID_VALID ; 
 scalar_t__ NO_CABLE ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  icom_lock ; 
 TYPE_5__* int_mask_tbl ; 
 int /*<<< orphan*/  load_code (struct icom_port*) ; 
 unsigned char readb (int /*<<< orphan*/ *) ; 
 unsigned long readl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  trace (struct icom_port*,char*,unsigned char) ; 
 int /*<<< orphan*/  writel (unsigned long,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writew (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int startup(struct icom_port *icom_port)
{
	unsigned long temp;
	unsigned char cable_id, raw_cable_id;
	unsigned long flags;
	int port;

	trace(icom_port, "STARTUP", 0);

	if (!icom_port->dram) {
		/* should NEVER be NULL */
		dev_err(&icom_port->adapter->pci_dev->dev,
			"Unusable Port, port configuration missing\n");
		return -ENODEV;
	}

	/*
	 * check Cable ID
	 */
	raw_cable_id = readb(&icom_port->dram->cable_id);
	trace(icom_port, "CABLE_ID", raw_cable_id);

	/* Get cable ID into the lower 4 bits (standard form) */
	cable_id = (raw_cable_id & ICOM_CABLE_ID_MASK) >> 4;

	/* Check for valid Cable ID */
	if (!(raw_cable_id & ICOM_CABLE_ID_VALID) ||
	    (cable_id != icom_port->cable_id)) {

		/* reload adapter code, pick up any potential changes in cable id */
		load_code(icom_port);

		/* still no sign of cable, error out */
		raw_cable_id = readb(&icom_port->dram->cable_id);
		cable_id = (raw_cable_id & ICOM_CABLE_ID_MASK) >> 4;
		if (!(raw_cable_id & ICOM_CABLE_ID_VALID) ||
		    (icom_port->cable_id == NO_CABLE))
			return -EIO;
	}

	/*
	 * Finally, clear and  enable interrupts
	 */
	spin_lock_irqsave(&icom_lock, flags);
	port = icom_port->port;
	if (port >= ARRAY_SIZE(int_mask_tbl)) {
		dev_err(&icom_port->adapter->pci_dev->dev,
			"Invalid port assignment\n");
		goto unlock;
	}

	if (port == 0 || port == 1)
		int_mask_tbl[port].global_int_mask = &icom_port->global_reg->int_mask;
	else
		int_mask_tbl[port].global_int_mask = &icom_port->global_reg->int_mask_2;

	if (port == 0 || port == 2)
		writew(0x00FF, icom_port->int_reg);
	else
		writew(0x3F00, icom_port->int_reg);

	temp = readl(int_mask_tbl[port].global_int_mask);
	writel(temp & ~int_mask_tbl[port].processor_id, int_mask_tbl[port].global_int_mask);

	/* write flush */
	readl(int_mask_tbl[port].global_int_mask);

unlock:
	spin_unlock_irqrestore(&icom_lock, flags);
	return 0;
}