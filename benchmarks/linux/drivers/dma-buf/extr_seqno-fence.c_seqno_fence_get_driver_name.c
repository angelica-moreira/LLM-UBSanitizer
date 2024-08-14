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
struct seqno_fence {TYPE_1__* ops; } ;
struct dma_fence {int dummy; } ;
struct TYPE_2__ {char const* (* get_driver_name ) (struct dma_fence*) ;} ;

/* Variables and functions */
 char const* stub1 (struct dma_fence*) ; 
 struct seqno_fence* to_seqno_fence (struct dma_fence*) ; 

__attribute__((used)) static const char *seqno_fence_get_driver_name(struct dma_fence *fence)
{
	struct seqno_fence *seqno_fence = to_seqno_fence(fence);

	return seqno_fence->ops->get_driver_name(fence);
}