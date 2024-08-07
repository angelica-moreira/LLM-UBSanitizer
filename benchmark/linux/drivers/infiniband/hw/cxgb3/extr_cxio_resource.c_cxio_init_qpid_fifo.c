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
typedef  int u32 ;
struct cxio_rdev {int qpmask; TYPE_1__* rscp; } ;
struct TYPE_2__ {int /*<<< orphan*/  qpid_fifo; int /*<<< orphan*/  qpid_fifo_lock; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int T3_MAX_NUM_QP ; 
 scalar_t__ kfifo_alloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfifo_in (int /*<<< orphan*/ *,unsigned char*,int) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int cxio_init_qpid_fifo(struct cxio_rdev *rdev_p)
{
	u32 i;

	spin_lock_init(&rdev_p->rscp->qpid_fifo_lock);

	if (kfifo_alloc(&rdev_p->rscp->qpid_fifo, T3_MAX_NUM_QP * sizeof(u32),
					      GFP_KERNEL))
		return -ENOMEM;

	for (i = 16; i < T3_MAX_NUM_QP; i++)
		if (!(i & rdev_p->qpmask))
			kfifo_in(&rdev_p->rscp->qpid_fifo,
				    (unsigned char *) &i, sizeof(u32));
	return 0;
}