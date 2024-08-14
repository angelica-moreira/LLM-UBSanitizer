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
struct hfi1_pportdata {int /*<<< orphan*/ * link_wq; int /*<<< orphan*/ * hfi1_wq; } ;
struct hfi1_devdata {int num_pports; struct hfi1_pportdata* pport; int /*<<< orphan*/  unit; } ;

/* Variables and functions */
 int ENOMEM ; 
 int HFI1_MAX_ACTIVE_WORKQUEUE_ENTRIES ; 
 int WQ_CPU_INTENSIVE ; 
 int WQ_HIGHPRI ; 
 int WQ_MEM_RECLAIM ; 
 int WQ_SYSFS ; 
 int WQ_UNBOUND ; 
 void* alloc_workqueue (char*,int,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  destroy_workqueue (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 

__attribute__((used)) static int create_workqueues(struct hfi1_devdata *dd)
{
	int pidx;
	struct hfi1_pportdata *ppd;

	for (pidx = 0; pidx < dd->num_pports; ++pidx) {
		ppd = dd->pport + pidx;
		if (!ppd->hfi1_wq) {
			ppd->hfi1_wq =
				alloc_workqueue(
				    "hfi%d_%d",
				    WQ_SYSFS | WQ_HIGHPRI | WQ_CPU_INTENSIVE |
				    WQ_MEM_RECLAIM,
				    HFI1_MAX_ACTIVE_WORKQUEUE_ENTRIES,
				    dd->unit, pidx);
			if (!ppd->hfi1_wq)
				goto wq_error;
		}
		if (!ppd->link_wq) {
			/*
			 * Make the link workqueue single-threaded to enforce
			 * serialization.
			 */
			ppd->link_wq =
				alloc_workqueue(
				    "hfi_link_%d_%d",
				    WQ_SYSFS | WQ_MEM_RECLAIM | WQ_UNBOUND,
				    1, /* max_active */
				    dd->unit, pidx);
			if (!ppd->link_wq)
				goto wq_error;
		}
	}
	return 0;
wq_error:
	pr_err("alloc_workqueue failed for port %d\n", pidx + 1);
	for (pidx = 0; pidx < dd->num_pports; ++pidx) {
		ppd = dd->pport + pidx;
		if (ppd->hfi1_wq) {
			destroy_workqueue(ppd->hfi1_wq);
			ppd->hfi1_wq = NULL;
		}
		if (ppd->link_wq) {
			destroy_workqueue(ppd->link_wq);
			ppd->link_wq = NULL;
		}
	}
	return -ENOMEM;
}