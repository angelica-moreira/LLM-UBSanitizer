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
struct seq_file {int /*<<< orphan*/  private; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATA_SMART_READ_THRESHOLDS ; 
 int __idedisk_proc_show (struct seq_file*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int idedisk_st_proc_show(struct seq_file *m, void *v)
{
	return __idedisk_proc_show(m, m->private, ATA_SMART_READ_THRESHOLDS);
}