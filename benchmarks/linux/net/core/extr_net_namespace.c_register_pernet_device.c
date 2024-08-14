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
struct pernet_operations {int /*<<< orphan*/  list; } ;

/* Variables and functions */
 int /*<<< orphan*/  down_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * first_device ; 
 int /*<<< orphan*/  pernet_list ; 
 int /*<<< orphan*/  pernet_ops_rwsem ; 
 int register_pernet_operations (int /*<<< orphan*/ *,struct pernet_operations*) ; 
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 

int register_pernet_device(struct pernet_operations *ops)
{
	int error;
	down_write(&pernet_ops_rwsem);
	error = register_pernet_operations(&pernet_list, ops);
	if (!error && (first_device == &pernet_list))
		first_device = &ops->list;
	up_write(&pernet_ops_rwsem);
	return error;
}