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
typedef  int u32 ;
struct seq_file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,...) ; 
 int /*<<< orphan*/  seq_putc (struct seq_file*,char) ; 

__attribute__((used)) static void bdisp_dbg_dump_rsf(struct seq_file *s, u32 val, char *name)
{
	u32 inc;

	seq_printf(s, "%s\t0x%08X\t", name, val);

	if (!val)
		goto done;

	inc = val & 0xFFFF;
	seq_printf(s, "H: %d(6.10) / scale~%dx0.1 - ", inc, 1024 * 10 / inc);

	inc = val >> 16;
	seq_printf(s, "V: %d(6.10) / scale~%dx0.1", inc, 1024 * 10 / inc);

done:
	seq_putc(s, '\n');
}