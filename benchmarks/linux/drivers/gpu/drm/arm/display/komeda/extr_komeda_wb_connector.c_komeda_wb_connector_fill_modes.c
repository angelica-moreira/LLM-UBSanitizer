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
typedef  int /*<<< orphan*/  uint32_t ;
struct drm_connector {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int
komeda_wb_connector_fill_modes(struct drm_connector *connector,
			       uint32_t maxX, uint32_t maxY)
{
	return 0;
}