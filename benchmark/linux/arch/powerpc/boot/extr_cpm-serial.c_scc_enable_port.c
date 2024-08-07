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
struct TYPE_2__ {int /*<<< orphan*/  gsmrl; } ;

/* Variables and functions */
 int /*<<< orphan*/  CPM_CMD_RESTART_TX ; 
 int /*<<< orphan*/  do_cmd (int /*<<< orphan*/ ) ; 
 int in_be32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  out_be32 (int /*<<< orphan*/ *,int) ; 
 TYPE_1__* scc ; 

__attribute__((used)) static void scc_enable_port(void)
{
	out_be32(&scc->gsmrl, in_be32(&scc->gsmrl) | 0x30);
	do_cmd(CPM_CMD_RESTART_TX);
}