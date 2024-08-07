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
typedef  int /*<<< orphan*/  u32 ;
struct seq_file {struct mvpp2_dbgfs_flow_tbl_entry* private; } ;
struct mvpp2_dbgfs_flow_tbl_entry {int /*<<< orphan*/  id; int /*<<< orphan*/  priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  mvpp2_cls_flow_hits (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mvpp2_dbgfs_flow_flt_hits_show(struct seq_file *s, void *unused)
{
	struct mvpp2_dbgfs_flow_tbl_entry *entry = s->private;

	u32 hits = mvpp2_cls_flow_hits(entry->priv, entry->id);

	seq_printf(s, "%u\n", hits);

	return 0;
}