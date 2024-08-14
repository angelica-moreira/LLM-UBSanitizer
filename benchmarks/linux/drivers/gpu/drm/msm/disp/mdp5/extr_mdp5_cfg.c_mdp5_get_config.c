#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct platform_device {int dummy; } ;
struct mdp5_cfg_platform {TYPE_2__* iommu; } ;
struct TYPE_3__ {int aperture_start; int aperture_end; } ;
struct TYPE_4__ {TYPE_1__ geometry; } ;

/* Variables and functions */
 TYPE_2__* iommu_domain_alloc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  platform_bus_type ; 

__attribute__((used)) static struct mdp5_cfg_platform *mdp5_get_config(struct platform_device *dev)
{
	static struct mdp5_cfg_platform config = {};

	config.iommu = iommu_domain_alloc(&platform_bus_type);
	if (config.iommu) {
		config.iommu->geometry.aperture_start = 0x1000;
		config.iommu->geometry.aperture_end = 0xffffffff;
	}

	return &config;
}