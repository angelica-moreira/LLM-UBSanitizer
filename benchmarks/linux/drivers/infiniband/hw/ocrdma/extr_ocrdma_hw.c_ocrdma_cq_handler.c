#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u16 ;
struct TYPE_3__ {scalar_t__ id; } ;
struct TYPE_4__ {TYPE_1__ cq; } ;
struct ocrdma_dev {TYPE_2__ mq; } ;

/* Variables and functions */
 int /*<<< orphan*/  ocrdma_mq_cq_handler (struct ocrdma_dev*,scalar_t__) ; 
 int /*<<< orphan*/  ocrdma_qp_cq_handler (struct ocrdma_dev*,scalar_t__) ; 

__attribute__((used)) static void ocrdma_cq_handler(struct ocrdma_dev *dev, u16 cq_id)
{
	/* process the MQ-CQE. */
	if (cq_id == dev->mq.cq.id)
		ocrdma_mq_cq_handler(dev, cq_id);
	else
		ocrdma_qp_cq_handler(dev, cq_id);
}