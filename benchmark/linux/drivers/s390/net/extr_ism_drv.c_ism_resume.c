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
struct ism_dev {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 struct ism_dev* dev_get_drvdata (struct device*) ; 
 int ism_dev_init (struct ism_dev*) ; 

__attribute__((used)) static int ism_resume(struct device *dev)
{
	struct ism_dev *ism = dev_get_drvdata(dev);

	return ism_dev_init(ism);
}