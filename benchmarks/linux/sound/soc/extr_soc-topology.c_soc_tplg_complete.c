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
struct soc_tplg {scalar_t__ comp; TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* complete ) (scalar_t__) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (scalar_t__) ; 

__attribute__((used)) static void soc_tplg_complete(struct soc_tplg *tplg)
{
	if (tplg->comp && tplg->ops && tplg->ops->complete)
		tplg->ops->complete(tplg->comp);
}