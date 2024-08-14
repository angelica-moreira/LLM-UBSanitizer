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
typedef  int /*<<< orphan*/  u8 ;
struct dentry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  debugfs_create_x8 (char const*,int /*<<< orphan*/ ,struct dentry*,int /*<<< orphan*/ *) ; 
 struct dentry* edac_debugfs ; 

void edac_debugfs_create_x8(const char *name, umode_t mode,
			    struct dentry *parent, u8 *value)
{
	if (!parent)
		parent = edac_debugfs;

	debugfs_create_x8(name, mode, parent, value);
}