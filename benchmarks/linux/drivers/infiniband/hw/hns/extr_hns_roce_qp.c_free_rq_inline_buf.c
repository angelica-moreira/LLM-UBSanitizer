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
struct TYPE_3__ {TYPE_2__* wqe_list; } ;
struct hns_roce_qp {TYPE_1__ rq_inl_buf; } ;
struct TYPE_4__ {struct TYPE_4__* sg_list; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (TYPE_2__*) ; 

__attribute__((used)) static void free_rq_inline_buf(struct hns_roce_qp *hr_qp)
{
	kfree(hr_qp->rq_inl_buf.wqe_list[0].sg_list);
	kfree(hr_qp->rq_inl_buf.wqe_list);
}