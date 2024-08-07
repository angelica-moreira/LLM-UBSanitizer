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
struct mei_me_client {int /*<<< orphan*/  refcnt; } ;

/* Variables and functions */
 scalar_t__ kref_get_unless_zero (int /*<<< orphan*/ *) ; 

struct mei_me_client *mei_me_cl_get(struct mei_me_client *me_cl)
{
	if (me_cl && kref_get_unless_zero(&me_cl->refcnt))
		return me_cl;

	return NULL;
}