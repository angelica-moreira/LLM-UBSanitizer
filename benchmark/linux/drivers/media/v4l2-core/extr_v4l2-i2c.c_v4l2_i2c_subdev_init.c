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
struct v4l2_subdev_ops {int dummy; } ;
struct v4l2_subdev {TYPE_2__* dev; int /*<<< orphan*/  owner; int /*<<< orphan*/  flags; } ;
struct TYPE_4__ {TYPE_1__* driver; } ;
struct i2c_client {TYPE_2__ dev; } ;
struct TYPE_3__ {int /*<<< orphan*/  owner; } ;

/* Variables and functions */
 int /*<<< orphan*/  V4L2_SUBDEV_FL_IS_I2C ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct v4l2_subdev*) ; 
 int /*<<< orphan*/  v4l2_i2c_subdev_set_name (struct v4l2_subdev*,struct i2c_client*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  v4l2_set_subdevdata (struct v4l2_subdev*,struct i2c_client*) ; 
 int /*<<< orphan*/  v4l2_subdev_init (struct v4l2_subdev*,struct v4l2_subdev_ops const*) ; 

void v4l2_i2c_subdev_init(struct v4l2_subdev *sd, struct i2c_client *client,
			  const struct v4l2_subdev_ops *ops)
{
	v4l2_subdev_init(sd, ops);
	sd->flags |= V4L2_SUBDEV_FL_IS_I2C;
	/* the owner is the same as the i2c_client's driver owner */
	sd->owner = client->dev.driver->owner;
	sd->dev = &client->dev;
	/* i2c_client and v4l2_subdev point to one another */
	v4l2_set_subdevdata(sd, client);
	i2c_set_clientdata(client, sd);
	v4l2_i2c_subdev_set_name(sd, client, NULL, NULL);
}