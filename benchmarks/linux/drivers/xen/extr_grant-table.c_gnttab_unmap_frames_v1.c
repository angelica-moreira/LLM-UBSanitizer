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
struct TYPE_2__ {int /*<<< orphan*/  addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  arch_gnttab_unmap (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_1__ gnttab_shared ; 
 int /*<<< orphan*/  nr_grant_frames ; 

__attribute__((used)) static void gnttab_unmap_frames_v1(void)
{
	arch_gnttab_unmap(gnttab_shared.addr, nr_grant_frames);
}