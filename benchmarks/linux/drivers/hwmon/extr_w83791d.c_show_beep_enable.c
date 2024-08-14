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
struct w83791d_data {int beep_enable; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 struct w83791d_data* w83791d_update_device (struct device*) ; 

__attribute__((used)) static ssize_t show_beep_enable(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct w83791d_data *data = w83791d_update_device(dev);
	return sprintf(buf, "%d\n", data->beep_enable);
}