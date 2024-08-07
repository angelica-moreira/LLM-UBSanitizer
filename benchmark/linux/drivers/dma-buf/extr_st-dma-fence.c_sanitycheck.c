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
struct dma_fence {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  dma_fence_put (struct dma_fence*) ; 
 int /*<<< orphan*/  dma_fence_signal (struct dma_fence*) ; 
 struct dma_fence* mock_fence () ; 

__attribute__((used)) static int sanitycheck(void *arg)
{
	struct dma_fence *f;

	f = mock_fence();
	if (!f)
		return -ENOMEM;

	dma_fence_signal(f);
	dma_fence_put(f);

	return 0;
}