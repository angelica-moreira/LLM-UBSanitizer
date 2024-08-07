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
struct uverbs_attr_bundle {int /*<<< orphan*/  driver_udata; } ;
struct ib_uobject {struct ib_pd* object; } ;
struct ib_pd {int /*<<< orphan*/  usecnt; } ;
typedef  enum rdma_remove_reason { ____Placeholder_rdma_remove_reason } rdma_remove_reason ;

/* Variables and functions */
 int /*<<< orphan*/  ib_dealloc_pd_user (struct ib_pd*,int /*<<< orphan*/ *) ; 
 int ib_destroy_usecnt (int /*<<< orphan*/ *,int,struct ib_uobject*) ; 

__attribute__((used)) static int uverbs_free_pd(struct ib_uobject *uobject,
			  enum rdma_remove_reason why,
			  struct uverbs_attr_bundle *attrs)
{
	struct ib_pd *pd = uobject->object;
	int ret;

	ret = ib_destroy_usecnt(&pd->usecnt, why, uobject);
	if (ret)
		return ret;

	ib_dealloc_pd_user(pd, &attrs->driver_udata);
	return 0;
}