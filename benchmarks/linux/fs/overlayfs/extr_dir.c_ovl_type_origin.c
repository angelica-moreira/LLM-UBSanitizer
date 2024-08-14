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
struct dentry {int dummy; } ;

/* Variables and functions */
 int OVL_TYPE_ORIGIN (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ovl_path_type (struct dentry*) ; 

__attribute__((used)) static bool ovl_type_origin(struct dentry *dentry)
{
	return OVL_TYPE_ORIGIN(ovl_path_type(dentry));
}