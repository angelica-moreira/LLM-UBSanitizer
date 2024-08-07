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
struct v4l2_fwnode_bus_conv {int mbus_type; } ;
typedef  enum v4l2_mbus_type { ____Placeholder_v4l2_mbus_type } v4l2_mbus_type ;
typedef  enum v4l2_fwnode_bus_type { ____Placeholder_v4l2_fwnode_bus_type } v4l2_fwnode_bus_type ;

/* Variables and functions */
 int V4L2_MBUS_UNKNOWN ; 
 struct v4l2_fwnode_bus_conv* get_v4l2_fwnode_bus_conv_by_fwnode_bus (int) ; 

__attribute__((used)) static enum v4l2_mbus_type
v4l2_fwnode_bus_type_to_mbus(enum v4l2_fwnode_bus_type type)
{
	const struct v4l2_fwnode_bus_conv *conv =
		get_v4l2_fwnode_bus_conv_by_fwnode_bus(type);

	return conv ? conv->mbus_type : V4L2_MBUS_UNKNOWN;
}