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
struct TYPE_3__ {scalar_t__ start; } ;
struct TYPE_4__ {scalar_t__ resource_valid; TYPE_1__ ifp_resource; scalar_t__ i9xx_flush_page; } ;

/* Variables and functions */
 TYPE_2__ intel_private ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int /*<<< orphan*/  release_resource (TYPE_1__*) ; 

__attribute__((used)) static void i9xx_cleanup(void)
{
	if (intel_private.i9xx_flush_page)
		iounmap(intel_private.i9xx_flush_page);
	if (intel_private.resource_valid)
		release_resource(&intel_private.ifp_resource);
	intel_private.ifp_resource.start = 0;
	intel_private.resource_valid = 0;
}