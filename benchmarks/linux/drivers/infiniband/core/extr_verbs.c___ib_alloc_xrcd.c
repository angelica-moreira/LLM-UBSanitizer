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
struct ib_xrcd {int /*<<< orphan*/  tgt_qp_list; int /*<<< orphan*/  tgt_qp_mutex; int /*<<< orphan*/  usecnt; int /*<<< orphan*/ * inode; struct ib_device* device; } ;
struct TYPE_2__ {struct ib_xrcd* (* alloc_xrcd ) (struct ib_device*,int /*<<< orphan*/ *) ;} ;
struct ib_device {TYPE_1__ ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  EOPNOTSUPP ; 
 struct ib_xrcd* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IS_ERR (struct ib_xrcd*) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 struct ib_xrcd* stub1 (struct ib_device*,int /*<<< orphan*/ *) ; 

struct ib_xrcd *__ib_alloc_xrcd(struct ib_device *device, const char *caller)
{
	struct ib_xrcd *xrcd;

	if (!device->ops.alloc_xrcd)
		return ERR_PTR(-EOPNOTSUPP);

	xrcd = device->ops.alloc_xrcd(device, NULL);
	if (!IS_ERR(xrcd)) {
		xrcd->device = device;
		xrcd->inode = NULL;
		atomic_set(&xrcd->usecnt, 0);
		mutex_init(&xrcd->tgt_qp_mutex);
		INIT_LIST_HEAD(&xrcd->tgt_qp_list);
	}

	return xrcd;
}