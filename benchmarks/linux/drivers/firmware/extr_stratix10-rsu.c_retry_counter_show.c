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
struct stratix10_rsu_priv {int retry_counter; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ENODEV ; 
 struct stratix10_rsu_priv* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t retry_counter_show(struct device *dev,
				  struct device_attribute *attr, char *buf)
{
	struct stratix10_rsu_priv *priv = dev_get_drvdata(dev);

	if (!priv)
		return -ENODEV;

	return sprintf(buf, "0x%08x\n", priv->retry_counter);
}