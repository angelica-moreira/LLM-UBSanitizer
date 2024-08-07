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

/* Variables and functions */
 int /*<<< orphan*/  class_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  host_index_ida ; 
 int /*<<< orphan*/  ida_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  shost_class ; 

void scsi_exit_hosts(void)
{
	class_unregister(&shost_class);
	ida_destroy(&host_index_ida);
}