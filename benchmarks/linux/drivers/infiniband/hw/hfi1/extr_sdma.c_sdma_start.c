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
struct sdma_engine {int dummy; } ;
struct hfi1_devdata {unsigned int num_sdma; struct sdma_engine* per_sdma; } ;

/* Variables and functions */
 int /*<<< orphan*/  sdma_event_e10_go_hw_start ; 
 int /*<<< orphan*/  sdma_process_event (struct sdma_engine*,int /*<<< orphan*/ ) ; 

void sdma_start(struct hfi1_devdata *dd)
{
	unsigned i;
	struct sdma_engine *sde;

	/* kick off the engines state processing */
	for (i = 0; i < dd->num_sdma; ++i) {
		sde = &dd->per_sdma[i];
		sdma_process_event(sde, sdma_event_e10_go_hw_start);
	}
}