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
struct il_priv {int temperature; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  EAGAIN ; 
 struct il_priv* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  il_is_alive (struct il_priv*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t
il4965_show_temperature(struct device *d, struct device_attribute *attr,
			char *buf)
{
	struct il_priv *il = dev_get_drvdata(d);

	if (!il_is_alive(il))
		return -EAGAIN;

	return sprintf(buf, "%d\n", il->temperature);
}