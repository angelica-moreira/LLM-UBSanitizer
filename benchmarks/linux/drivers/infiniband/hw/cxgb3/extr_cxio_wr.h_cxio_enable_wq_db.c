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
struct t3_wq {TYPE_2__* queue; } ;
struct TYPE_3__ {int err; } ;
struct TYPE_4__ {TYPE_1__ wq_in_err; } ;

/* Variables and functions */

__attribute__((used)) static inline void cxio_enable_wq_db(struct t3_wq *wq)
{
	wq->queue->wq_in_err.err &= ~2;
}