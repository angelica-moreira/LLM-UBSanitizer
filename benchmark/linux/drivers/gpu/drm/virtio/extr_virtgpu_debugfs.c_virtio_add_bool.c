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

/* Variables and functions */
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,char const*,char*) ; 

__attribute__((used)) static void virtio_add_bool(struct seq_file *m, const char *name,
				    bool value)
{
	seq_printf(m, "%-16s : %s\n", name, value ? "yes" : "no");
}