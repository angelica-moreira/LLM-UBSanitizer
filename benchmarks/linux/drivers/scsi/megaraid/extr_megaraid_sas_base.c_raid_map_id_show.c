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
struct megasas_instance {scalar_t__ map_id; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct Scsi_Host {scalar_t__ hostdata; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 struct Scsi_Host* class_to_shost (struct device*) ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,unsigned long) ; 

__attribute__((used)) static ssize_t
raid_map_id_show(struct device *cdev, struct device_attribute *attr,
			  char *buf)
{
	struct Scsi_Host *shost = class_to_shost(cdev);
	struct megasas_instance *instance =
			(struct megasas_instance *)shost->hostdata;

	return snprintf(buf, PAGE_SIZE, "%ld\n",
			(unsigned long)instance->map_id);
}