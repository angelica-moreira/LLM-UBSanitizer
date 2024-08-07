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
struct trigger {int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int /*<<< orphan*/  TRIGGER_OFF ; 
 int /*<<< orphan*/  trigger_is_available (struct trigger*) ; 

__attribute__((used)) static inline void trigger_off(struct trigger *t)
{
	if (!trigger_is_available(t))
		return;
	t->state = TRIGGER_OFF;
}