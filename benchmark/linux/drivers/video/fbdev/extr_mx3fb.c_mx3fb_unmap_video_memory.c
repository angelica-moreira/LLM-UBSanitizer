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
struct TYPE_2__ {scalar_t__ smem_len; scalar_t__ smem_start; } ;
struct fb_info {int /*<<< orphan*/  mm_lock; TYPE_1__ fix; int /*<<< orphan*/ * screen_base; int /*<<< orphan*/  device; } ;

/* Variables and functions */
 int /*<<< orphan*/  dma_free_wc (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int mx3fb_unmap_video_memory(struct fb_info *fbi)
{
	dma_free_wc(fbi->device, fbi->fix.smem_len, fbi->screen_base,
		    fbi->fix.smem_start);

	fbi->screen_base = NULL;
	mutex_lock(&fbi->mm_lock);
	fbi->fix.smem_start = 0;
	fbi->fix.smem_len = 0;
	mutex_unlock(&fbi->mm_lock);
	return 0;
}