#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_4__ {int /*<<< orphan*/  total_isp_aborts; } ;
struct TYPE_5__ {TYPE_1__ qla_stats; } ;
typedef  TYPE_2__ scsi_qla_host_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  class_to_shost (struct device*) ; 
 int /*<<< orphan*/  scnprintf (char*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 TYPE_2__* shost_priv (int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t
qla2x00_total_isp_aborts_show(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	scsi_qla_host_t *vha = shost_priv(class_to_shost(dev));

	return scnprintf(buf, PAGE_SIZE, "%d\n",
	    vha->qla_stats.total_isp_aborts);
}