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
struct afs_call {int /*<<< orphan*/  ret_vldb; } ;

/* Variables and functions */
 int /*<<< orphan*/  afs_flat_call_destructor (struct afs_call*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void afs_destroy_vl_get_entry_by_name_u(struct afs_call *call)
{
	kfree(call->ret_vldb);
	afs_flat_call_destructor(call);
}