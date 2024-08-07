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
struct omap_dss_device {int /*<<< orphan*/  next; int /*<<< orphan*/  dss; } ;

/* Variables and functions */
 int omapdss_device_connect (int /*<<< orphan*/ ,struct omap_dss_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int sdi_connect(struct omap_dss_device *src,
		       struct omap_dss_device *dst)
{
	return omapdss_device_connect(dst->dss, dst, dst->next);
}