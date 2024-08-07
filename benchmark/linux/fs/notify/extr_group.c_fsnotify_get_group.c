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
struct fsnotify_group {int /*<<< orphan*/  refcnt; } ;

/* Variables and functions */
 int /*<<< orphan*/  refcount_inc (int /*<<< orphan*/ *) ; 

void fsnotify_get_group(struct fsnotify_group *group)
{
	refcount_inc(&group->refcnt);
}