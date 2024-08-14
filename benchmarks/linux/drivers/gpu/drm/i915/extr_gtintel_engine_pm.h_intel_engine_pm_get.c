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
struct intel_engine_cs {int /*<<< orphan*/  wakeref; } ;

/* Variables and functions */
 int /*<<< orphan*/  intel_wakeref_get (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void intel_engine_pm_get(struct intel_engine_cs *engine)
{
	intel_wakeref_get(&engine->wakeref);
}