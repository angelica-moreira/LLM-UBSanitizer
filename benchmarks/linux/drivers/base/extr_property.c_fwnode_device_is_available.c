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
struct fwnode_handle {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  device_is_available ; 
 int fwnode_call_bool_op (struct fwnode_handle const*,int /*<<< orphan*/ ) ; 

bool fwnode_device_is_available(const struct fwnode_handle *fwnode)
{
	return fwnode_call_bool_op(fwnode, device_is_available);
}