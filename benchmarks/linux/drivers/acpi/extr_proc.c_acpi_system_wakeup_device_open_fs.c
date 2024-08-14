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
struct inode {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PDE_DATA (struct inode*) ; 
 int /*<<< orphan*/  acpi_system_wakeup_device_seq_show ; 
 int single_open (struct file*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
acpi_system_wakeup_device_open_fs(struct inode *inode, struct file *file)
{
	return single_open(file, acpi_system_wakeup_device_seq_show,
			   PDE_DATA(inode));
}