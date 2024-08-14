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
struct vringh_iov {int max_num; int used; int i; int consumed; int /*<<< orphan*/ * iov; } ;

/* Variables and functions */
 int VRINGH_IOV_ALLOCATED ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void vringh_iov_cleanup(struct vringh_iov *iov)
{
	if (iov->max_num & VRINGH_IOV_ALLOCATED)
		kfree(iov->iov);
	iov->max_num = iov->used = iov->i = iov->consumed = 0;
	iov->iov = NULL;
}