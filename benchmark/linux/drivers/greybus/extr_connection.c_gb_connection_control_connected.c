#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u16 ;
struct gb_control {int dummy; } ;
struct gb_connection {TYPE_2__* bundle; TYPE_1__* intf; int /*<<< orphan*/  intf_cport_id; } ;
struct TYPE_4__ {int /*<<< orphan*/  dev; } ;
struct TYPE_3__ {struct gb_control* control; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 scalar_t__ gb_connection_is_control (struct gb_connection*) ; 
 scalar_t__ gb_connection_is_static (struct gb_connection*) ; 
 int gb_control_connected_operation (struct gb_control*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int gb_connection_control_connected(struct gb_connection *connection)
{
	struct gb_control *control;
	u16 cport_id = connection->intf_cport_id;
	int ret;

	if (gb_connection_is_static(connection))
		return 0;

	if (gb_connection_is_control(connection))
		return 0;

	control = connection->intf->control;

	ret = gb_control_connected_operation(control, cport_id);
	if (ret) {
		dev_err(&connection->bundle->dev,
			"failed to connect cport: %d\n", ret);
		return ret;
	}

	return 0;
}