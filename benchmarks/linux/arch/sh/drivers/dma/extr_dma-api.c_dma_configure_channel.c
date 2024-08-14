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
struct dma_info {TYPE_1__* ops; } ;
struct dma_channel {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* configure ) (struct dma_channel*,unsigned long) ;} ;

/* Variables and functions */
 struct dma_channel* get_dma_channel (unsigned int) ; 
 struct dma_info* get_dma_info (unsigned int) ; 
 int /*<<< orphan*/  stub1 (struct dma_channel*,unsigned long) ; 

void dma_configure_channel(unsigned int chan, unsigned long flags)
{
	struct dma_info *info = get_dma_info(chan);
	struct dma_channel *channel = get_dma_channel(chan);

	if (info->ops->configure)
		info->ops->configure(channel, flags);
}