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
struct fw_unit {int /*<<< orphan*/  device; } ;
struct firedtv {scalar_t__ isochannel; int /*<<< orphan*/  subunit; } ;

/* Variables and functions */
 int /*<<< orphan*/  cmp_establish_pp_connection (struct firedtv*,int /*<<< orphan*/ ,scalar_t__) ; 
 struct firedtv* dev_get_drvdata (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void node_update(struct fw_unit *unit)
{
	struct firedtv *fdtv = dev_get_drvdata(&unit->device);

	if (fdtv->isochannel >= 0)
		cmp_establish_pp_connection(fdtv, fdtv->subunit,
					    fdtv->isochannel);
}