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
struct b43_dmaring {unsigned long last_injected_overflow; int /*<<< orphan*/  index; TYPE_1__* dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  wl; } ;

/* Variables and functions */
 int /*<<< orphan*/  B43_DBG_DMAOVERFLOW ; 
 unsigned long HZ ; 
 int /*<<< orphan*/  b43_debug (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 unsigned long jiffies ; 
 scalar_t__ time_after (unsigned long,unsigned long) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int should_inject_overflow(struct b43_dmaring *ring)
{
#ifdef CONFIG_B43_DEBUG
	if (unlikely(b43_debug(ring->dev, B43_DBG_DMAOVERFLOW))) {
		/* Check if we should inject another ringbuffer overflow
		 * to test handling of this situation in the stack. */
		unsigned long next_overflow;

		next_overflow = ring->last_injected_overflow + HZ;
		if (time_after(jiffies, next_overflow)) {
			ring->last_injected_overflow = jiffies;
			b43dbg(ring->dev->wl,
			       "Injecting TX ring overflow on "
			       "DMA controller %d\n", ring->index);
			return 1;
		}
	}
#endif /* CONFIG_B43_DEBUG */
	return 0;
}