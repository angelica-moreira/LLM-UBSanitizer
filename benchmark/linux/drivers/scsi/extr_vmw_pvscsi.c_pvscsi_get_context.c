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
typedef  int u64 ;
struct pvscsi_ctx {int dummy; } ;
struct pvscsi_adapter {struct pvscsi_ctx* cmd_map; } ;

/* Variables and functions */

__attribute__((used)) static struct pvscsi_ctx *
pvscsi_get_context(const struct pvscsi_adapter *adapter, u64 context)
{
	return &adapter->cmd_map[context - 1];
}