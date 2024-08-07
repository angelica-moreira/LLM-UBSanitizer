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
struct net_device {int dummy; } ;
struct ethtool_drvinfo {int /*<<< orphan*/  bus_info; int /*<<< orphan*/  fw_version; int /*<<< orphan*/  version; int /*<<< orphan*/  driver; } ;

/* Variables and functions */
 char* DRIVER_NAME ; 
 char* DRIVER_VERSION ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static void pxa168_get_drvinfo(struct net_device *dev,
			       struct ethtool_drvinfo *info)
{
	strlcpy(info->driver, DRIVER_NAME, sizeof(info->driver));
	strlcpy(info->version, DRIVER_VERSION, sizeof(info->version));
	strlcpy(info->fw_version, "N/A", sizeof(info->fw_version));
	strlcpy(info->bus_info, "N/A", sizeof(info->bus_info));
}