#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct lbs_private {int /*<<< orphan*/  mesh_dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_2__ {struct lbs_private* ml_priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 
 TYPE_1__* to_net_dev (struct device*) ; 

__attribute__((used)) static ssize_t lbs_mesh_get(struct device *dev,
		struct device_attribute *attr, char * buf)
{
	struct lbs_private *priv = to_net_dev(dev)->ml_priv;
	return snprintf(buf, 5, "0x%X\n", !!priv->mesh_dev);
}