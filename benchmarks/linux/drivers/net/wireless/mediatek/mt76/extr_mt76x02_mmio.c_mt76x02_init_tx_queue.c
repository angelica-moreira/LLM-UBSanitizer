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
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;
struct mt76x02_dev {TYPE_1__ mt76; } ;
struct mt76_sw_queue {struct mt76_queue* q; int /*<<< orphan*/  swq; } ;
struct mt76_queue {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  MT_INT_TX_DONE (int) ; 
 int /*<<< orphan*/  MT_TX_RING_BASE ; 
 struct mt76_queue* devm_kzalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int mt76_queue_alloc (struct mt76x02_dev*,struct mt76_queue*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mt76x02_irq_enable (struct mt76x02_dev*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
mt76x02_init_tx_queue(struct mt76x02_dev *dev, struct mt76_sw_queue *q,
		      int idx, int n_desc)
{
	struct mt76_queue *hwq;
	int err;

	hwq = devm_kzalloc(dev->mt76.dev, sizeof(*hwq), GFP_KERNEL);
	if (!hwq)
		return -ENOMEM;

	err = mt76_queue_alloc(dev, hwq, idx, n_desc, 0, MT_TX_RING_BASE);
	if (err < 0)
		return err;

	INIT_LIST_HEAD(&q->swq);
	q->q = hwq;

	mt76x02_irq_enable(dev, MT_INT_TX_DONE(idx));

	return 0;
}