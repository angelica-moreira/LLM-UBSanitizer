#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  mpi_limb_t ;
struct TYPE_3__ {unsigned int alloced; void* d; } ;
typedef  TYPE_1__* MPI ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* kcalloc (unsigned int,int,int /*<<< orphan*/ ) ; 
 void* kmalloc_array (unsigned int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kzfree (void*) ; 
 int /*<<< orphan*/  memcpy (void*,void*,int) ; 

int mpi_resize(MPI a, unsigned nlimbs)
{
	void *p;

	if (nlimbs <= a->alloced)
		return 0;	/* no need to do it */

	if (a->d) {
		p = kmalloc_array(nlimbs, sizeof(mpi_limb_t), GFP_KERNEL);
		if (!p)
			return -ENOMEM;
		memcpy(p, a->d, a->alloced * sizeof(mpi_limb_t));
		kzfree(a->d);
		a->d = p;
	} else {
		a->d = kcalloc(nlimbs, sizeof(mpi_limb_t), GFP_KERNEL);
		if (!a->d)
			return -ENOMEM;
	}
	a->alloced = nlimbs;
	return 0;
}