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
struct llt_ndlc {int powered; int /*<<< orphan*/  phy_id; TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* enable ) (int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 

int ndlc_open(struct llt_ndlc *ndlc)
{
	/* toggle reset pin */
	ndlc->ops->enable(ndlc->phy_id);
	ndlc->powered = 1;
	return 0;
}