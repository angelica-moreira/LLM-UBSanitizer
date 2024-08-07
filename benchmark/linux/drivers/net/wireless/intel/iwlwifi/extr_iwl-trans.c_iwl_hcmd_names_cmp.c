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
typedef  int u8 ;
struct iwl_hcmd_names {int cmd_id; } ;

/* Variables and functions */

__attribute__((used)) static int iwl_hcmd_names_cmp(const void *key, const void *elt)
{
	const struct iwl_hcmd_names *name = elt;
	u8 cmd1 = *(u8 *)key;
	u8 cmd2 = name->cmd_id;

	return (cmd1 - cmd2);
}