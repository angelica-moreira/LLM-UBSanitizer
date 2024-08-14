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
struct vhost_virtqueue {int dummy; } ;
struct vhost_net_ubuf_ref {struct vhost_virtqueue* vq; int /*<<< orphan*/  wait; int /*<<< orphan*/  refcount; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENOMEM ; 
 struct vhost_net_ubuf_ref* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 struct vhost_net_ubuf_ref* kmalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct vhost_net_ubuf_ref *
vhost_net_ubuf_alloc(struct vhost_virtqueue *vq, bool zcopy)
{
	struct vhost_net_ubuf_ref *ubufs;
	/* No zero copy backend? Nothing to count. */
	if (!zcopy)
		return NULL;
	ubufs = kmalloc(sizeof(*ubufs), GFP_KERNEL);
	if (!ubufs)
		return ERR_PTR(-ENOMEM);
	atomic_set(&ubufs->refcount, 1);
	init_waitqueue_head(&ubufs->wait);
	ubufs->vq = vq;
	return ubufs;
}