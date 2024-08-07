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
struct hvsi_struct {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  __set_state (struct hvsi_struct*,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline void set_state(struct hvsi_struct *hp, int state)
{
	unsigned long flags;

	spin_lock_irqsave(&hp->lock, flags);
	__set_state(hp, state);
	spin_unlock_irqrestore(&hp->lock, flags);
}