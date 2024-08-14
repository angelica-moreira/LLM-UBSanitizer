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
 int /*<<< orphan*/  debugfs_remove_recursive (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  visorbus_unregister_visor_driver (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  visornic_debugfs_dir ; 
 int /*<<< orphan*/  visornic_driver ; 

__attribute__((used)) static void visornic_cleanup(void)
{
	visorbus_unregister_visor_driver(&visornic_driver);
	debugfs_remove_recursive(visornic_debugfs_dir);
}