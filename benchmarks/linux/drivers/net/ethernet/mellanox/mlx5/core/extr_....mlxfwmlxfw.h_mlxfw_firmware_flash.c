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
struct netlink_ext_ack {int dummy; } ;
struct mlxfw_dev {int dummy; } ;
struct firmware {int dummy; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 

__attribute__((used)) static inline
int mlxfw_firmware_flash(struct mlxfw_dev *mlxfw_dev,
			 const struct firmware *firmware,
			 struct netlink_ext_ack *extack)
{
	return -EOPNOTSUPP;
}