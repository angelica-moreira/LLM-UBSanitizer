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
struct seq_file {int dummy; } ;
typedef  int /*<<< orphan*/  __le64 ;

/* Variables and functions */
 int le64_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int) ; 
 int /*<<< orphan*/  seq_puts (struct seq_file*,char*) ; 

__attribute__((used)) static void hisi_sas_show_row_64(struct seq_file *s, int index,
				 int sz, __le64 *ptr)
{
	int i;

	/* completion header size not fixed per HW version */
	seq_printf(s, "index %04d:\n\t", index);
	for (i = 1; i <= sz / 8; i++, ptr++) {
		seq_printf(s, " 0x%016llx", le64_to_cpu(*ptr));
		if (!(i % 2))
			seq_puts(s, "\n\t");
	}

	seq_puts(s, "\n");
}