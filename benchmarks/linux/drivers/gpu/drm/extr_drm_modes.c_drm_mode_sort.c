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
struct list_head {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  drm_mode_compare ; 
 int /*<<< orphan*/  list_sort (int /*<<< orphan*/ *,struct list_head*,int /*<<< orphan*/ ) ; 

void drm_mode_sort(struct list_head *mode_list)
{
	list_sort(NULL, mode_list, drm_mode_compare);
}