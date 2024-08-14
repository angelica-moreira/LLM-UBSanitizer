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
typedef  int /*<<< orphan*/  umode_t ;
struct proc_dir_entry {int dummy; } ;

/* Variables and functions */
 struct proc_dir_entry* proc_mkdir_data (char const*,int /*<<< orphan*/ ,struct proc_dir_entry*,int /*<<< orphan*/ *) ; 

struct proc_dir_entry *proc_mkdir_mode(const char *name, umode_t mode,
				       struct proc_dir_entry *parent)
{
	return proc_mkdir_data(name, mode, parent, NULL);
}