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
struct ceph_snap_context {int /*<<< orphan*/  nref; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct ceph_snap_context*) ; 
 scalar_t__ refcount_dec_and_test (int /*<<< orphan*/ *) ; 

void ceph_put_snap_context(struct ceph_snap_context *sc)
{
	if (!sc)
		return;
	if (refcount_dec_and_test(&sc->nref)) {
		/*printk(" deleting snap_context %p\n", sc);*/
		kfree(sc);
	}
}