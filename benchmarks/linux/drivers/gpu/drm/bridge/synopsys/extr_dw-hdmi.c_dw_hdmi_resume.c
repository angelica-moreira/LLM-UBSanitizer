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
struct dw_hdmi {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dw_hdmi_init_hw (struct dw_hdmi*) ; 

void dw_hdmi_resume(struct dw_hdmi *hdmi)
{
	dw_hdmi_init_hw(hdmi);
}