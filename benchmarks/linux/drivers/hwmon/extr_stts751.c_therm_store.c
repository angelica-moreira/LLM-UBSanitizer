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
struct stts751_priv {long therm; int /*<<< orphan*/  access_lock; scalar_t__ hyst; TYPE_1__* client; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  STTS751_REG_TLIM ; 
 long clamp_val (long,int,int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,long) ; 
 struct stts751_priv* dev_get_drvdata (struct device*) ; 
 scalar_t__ kstrtol (char const*,int,long*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int stts751_set_temp_reg8 (struct stts751_priv*,long,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t therm_store(struct device *dev, struct device_attribute *attr,
			   const char *buf, size_t count)
{
	int ret;
	long temp;
	struct stts751_priv *priv = dev_get_drvdata(dev);

	if (kstrtol(buf, 10, &temp) < 0)
		return -EINVAL;

	/* HW works in range -64C to +127.937C */
	temp = clamp_val(temp, -64000, 127937);
	mutex_lock(&priv->access_lock);
	ret = stts751_set_temp_reg8(priv, temp, STTS751_REG_TLIM);
	if (ret)
		goto exit;

	dev_dbg(&priv->client->dev, "setting therm %ld", temp);

	/*
	 * hysteresis reg is relative to therm, so the HW does not need to be
	 * adjusted, we need to update our local copy only.
	 */
	priv->hyst = temp - (priv->therm - priv->hyst);
	priv->therm = temp;

exit:
	mutex_unlock(&priv->access_lock);
	if (ret)
		return ret;

	return count;
}