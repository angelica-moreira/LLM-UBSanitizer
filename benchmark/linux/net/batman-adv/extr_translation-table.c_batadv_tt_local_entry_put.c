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
struct TYPE_2__ {int /*<<< orphan*/  refcount; } ;
struct batadv_tt_local_entry {TYPE_1__ common; } ;

/* Variables and functions */
 int /*<<< orphan*/  batadv_tt_local_entry_release ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
batadv_tt_local_entry_put(struct batadv_tt_local_entry *tt_local_entry)
{
	kref_put(&tt_local_entry->common.refcount,
		 batadv_tt_local_entry_release);
}