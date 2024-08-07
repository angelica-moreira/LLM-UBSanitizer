#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct mls_range {TYPE_3__* level; } ;
struct TYPE_5__ {TYPE_1__* level; } ;
struct context {TYPE_2__ range; } ;
struct TYPE_6__ {int /*<<< orphan*/  cat; int /*<<< orphan*/  sens; } ;
struct TYPE_4__ {int /*<<< orphan*/  cat; int /*<<< orphan*/  sens; } ;

/* Variables and functions */
 int ebitmap_cpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

int mls_range_set(struct context *context,
				struct mls_range *range)
{
	int l, rc = 0;

	/* Copy the MLS range into the  context */
	for (l = 0; l < 2; l++) {
		context->range.level[l].sens = range->level[l].sens;
		rc = ebitmap_cpy(&context->range.level[l].cat,
				 &range->level[l].cat);
		if (rc)
			break;
	}

	return rc;
}