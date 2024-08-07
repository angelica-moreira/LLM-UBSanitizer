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
struct scif_window {int offset_freed; } ;
struct TYPE_2__ {int /*<<< orphan*/  iovad; } ;
struct scif_endpt {TYPE_1__ rma_info; } ;
typedef  int s64 ;

/* Variables and functions */
 int PAGE_SHIFT ; 
 int /*<<< orphan*/  free_iova (int /*<<< orphan*/ *,int) ; 

void scif_free_window_offset(struct scif_endpt *ep,
			     struct scif_window *window, s64 offset)
{
	if ((window && !window->offset_freed) || !window) {
		free_iova(&ep->rma_info.iovad, offset >> PAGE_SHIFT);
		if (window)
			window->offset_freed = true;
	}
}