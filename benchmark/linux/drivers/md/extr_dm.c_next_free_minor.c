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

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GFP_NOWAIT ; 
 int MINORBITS ; 
 int /*<<< orphan*/  MINOR_ALLOCED ; 
 int /*<<< orphan*/  _minor_idr ; 
 int /*<<< orphan*/  _minor_lock ; 
 int idr_alloc (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  idr_preload (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  idr_preload_end () ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int next_free_minor(int *minor)
{
	int r;

	idr_preload(GFP_KERNEL);
	spin_lock(&_minor_lock);

	r = idr_alloc(&_minor_idr, MINOR_ALLOCED, 0, 1 << MINORBITS, GFP_NOWAIT);

	spin_unlock(&_minor_lock);
	idr_preload_end();
	if (r < 0)
		return r;
	*minor = r;
	return 0;
}