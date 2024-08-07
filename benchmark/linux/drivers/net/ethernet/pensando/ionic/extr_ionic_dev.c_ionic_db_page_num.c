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
struct ionic_lif {int hw_index; int dbid_count; } ;

/* Variables and functions */

int ionic_db_page_num(struct ionic_lif *lif, int pid)
{
	return (lif->hw_index * lif->dbid_count) + pid;
}