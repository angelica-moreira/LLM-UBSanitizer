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
struct trace_subsystem_dir {int ref_count; int /*<<< orphan*/  subsystem; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 int /*<<< orphan*/  __put_system (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct trace_subsystem_dir*) ; 
 int system_refcount (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void __put_system_dir(struct trace_subsystem_dir *dir)
{
	WARN_ON_ONCE(dir->ref_count == 0);
	/* If the subsystem is about to be freed, the dir must be too */
	WARN_ON_ONCE(system_refcount(dir->subsystem) == 1 && dir->ref_count != 1);

	__put_system(dir->subsystem);
	if (!--dir->ref_count)
		kfree(dir);
}