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
struct omap_video_timings {int dummy; } ;
struct omap_dss_device {int dummy; } ;
struct TYPE_2__ {struct omap_video_timings timings; } ;

/* Variables and functions */
 TYPE_1__ sdi ; 

__attribute__((used)) static void sdi_set_timings(struct omap_dss_device *dssdev,
		struct omap_video_timings *timings)
{
	sdi.timings = *timings;
}