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
struct ceph_authorizer {int /*<<< orphan*/  (* destroy ) (struct ceph_authorizer*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct ceph_authorizer*) ; 

void ceph_auth_destroy_authorizer(struct ceph_authorizer *a)
{
	a->destroy(a);
}