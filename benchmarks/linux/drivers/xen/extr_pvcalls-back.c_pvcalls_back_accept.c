#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct xenbus_device {int /*<<< orphan*/  dev; } ;
struct TYPE_6__ {int /*<<< orphan*/  id; } ;
struct TYPE_7__ {TYPE_1__ accept; } ;
struct xen_pvcalls_response {scalar_t__ cmd; int ret; TYPE_2__ u; int /*<<< orphan*/  req_id; } ;
struct TYPE_8__ {int /*<<< orphan*/  id; } ;
struct TYPE_9__ {TYPE_3__ accept; } ;
struct xen_pvcalls_request {scalar_t__ cmd; TYPE_4__ u; int /*<<< orphan*/  req_id; } ;
struct sockpass_mapping {int /*<<< orphan*/  register_work; int /*<<< orphan*/  wq; int /*<<< orphan*/  copy_lock; struct xen_pvcalls_request reqcopy; } ;
struct TYPE_10__ {int /*<<< orphan*/  rsp_prod_pvt; } ;
struct pvcalls_fedata {TYPE_5__ ring; int /*<<< orphan*/  socket_lock; int /*<<< orphan*/  socketpass_mappings; } ;

/* Variables and functions */
 int EINTR ; 
 int EINVAL ; 
 struct xen_pvcalls_response* RING_GET_RESPONSE (TYPE_5__*,int /*<<< orphan*/ ) ; 
 struct pvcalls_fedata* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  down (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  queue_work (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct sockpass_mapping* radix_tree_lookup (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int pvcalls_back_accept(struct xenbus_device *dev,
			       struct xen_pvcalls_request *req)
{
	struct pvcalls_fedata *fedata;
	struct sockpass_mapping *mappass;
	int ret = -EINVAL;
	struct xen_pvcalls_response *rsp;
	unsigned long flags;

	fedata = dev_get_drvdata(&dev->dev);

	down(&fedata->socket_lock);
	mappass = radix_tree_lookup(&fedata->socketpass_mappings,
		req->u.accept.id);
	up(&fedata->socket_lock);
	if (mappass == NULL)
		goto out_error;

	/*
	 * Limitation of the current implementation: only support one
	 * concurrent accept or poll call on one socket.
	 */
	spin_lock_irqsave(&mappass->copy_lock, flags);
	if (mappass->reqcopy.cmd != 0) {
		spin_unlock_irqrestore(&mappass->copy_lock, flags);
		ret = -EINTR;
		goto out_error;
	}

	mappass->reqcopy = *req;
	spin_unlock_irqrestore(&mappass->copy_lock, flags);
	queue_work(mappass->wq, &mappass->register_work);

	/* Tell the caller we don't need to send back a notification yet */
	return -1;

out_error:
	rsp = RING_GET_RESPONSE(&fedata->ring, fedata->ring.rsp_prod_pvt++);
	rsp->req_id = req->req_id;
	rsp->cmd = req->cmd;
	rsp->u.accept.id = req->u.accept.id;
	rsp->ret = ret;
	return 0;
}