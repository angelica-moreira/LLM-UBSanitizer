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
struct TYPE_3__ {int /*<<< orphan*/  mtmdsclock; } ;
struct TYPE_4__ {TYPE_1__ video_mode; } ;
struct dw_hdmi {unsigned int sample_rate; int /*<<< orphan*/  audio_mutex; TYPE_2__ hdmi_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  hdmi_set_clk_regenerator (struct dw_hdmi*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

void dw_hdmi_set_sample_rate(struct dw_hdmi *hdmi, unsigned int rate)
{
	mutex_lock(&hdmi->audio_mutex);
	hdmi->sample_rate = rate;
	hdmi_set_clk_regenerator(hdmi, hdmi->hdmi_data.video_mode.mtmdsclock,
				 hdmi->sample_rate);
	mutex_unlock(&hdmi->audio_mutex);
}