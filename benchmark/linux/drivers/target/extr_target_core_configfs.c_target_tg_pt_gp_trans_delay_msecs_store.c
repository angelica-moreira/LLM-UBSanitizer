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
struct config_item {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  core_alua_store_trans_delay_msecs (int /*<<< orphan*/ ,char const*,size_t) ; 
 int /*<<< orphan*/  to_tg_pt_gp (struct config_item*) ; 

__attribute__((used)) static ssize_t target_tg_pt_gp_trans_delay_msecs_store(struct config_item *item,
		const char *page, size_t count)
{
	return core_alua_store_trans_delay_msecs(to_tg_pt_gp(item), page,
			count);
}