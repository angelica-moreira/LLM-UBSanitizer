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
struct pvr2_ioread {int /*<<< orphan*/ * buffer_storage; } ;

/* Variables and functions */
 unsigned int BUFFER_COUNT ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pvr2_ioread_setup (struct pvr2_ioread*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void pvr2_ioread_done(struct pvr2_ioread *cp)
{
	unsigned int idx;

	pvr2_ioread_setup(cp,NULL);
	for (idx = 0; idx < BUFFER_COUNT; idx++) {
		if (!(cp->buffer_storage[idx])) continue;
		kfree(cp->buffer_storage[idx]);
	}
}