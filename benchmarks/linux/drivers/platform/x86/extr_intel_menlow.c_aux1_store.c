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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  aux_store (struct device*,struct device_attribute*,char const*,size_t,int) ; 

__attribute__((used)) static ssize_t aux1_store(struct device *dev,
			  struct device_attribute *dev_attr,
			  const char *buf, size_t count)
{
	return aux_store(dev, dev_attr, buf, count, 1);
}