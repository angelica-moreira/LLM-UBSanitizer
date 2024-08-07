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
struct ceph_auth_client {int /*<<< orphan*/  mutex; TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* invalidate_authorizer ) (struct ceph_auth_client*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct ceph_auth_client*,int) ; 

void ceph_auth_invalidate_authorizer(struct ceph_auth_client *ac, int peer_type)
{
	mutex_lock(&ac->mutex);
	if (ac->ops && ac->ops->invalidate_authorizer)
		ac->ops->invalidate_authorizer(ac, peer_type);
	mutex_unlock(&ac->mutex);
}