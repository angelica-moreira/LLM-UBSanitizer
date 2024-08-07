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
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_component {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int WM8993_HPOUT1L_ZC ; 
 int WM8993_HPOUT1R_ZC ; 
 int WM8993_HPOUT1_VU ; 
 int WM8993_IN1_VU ; 
 int WM8993_IN2_VU ; 
 int /*<<< orphan*/  WM8993_LEFT_LINE_INPUT_1_2_VOLUME ; 
 int /*<<< orphan*/  WM8993_LEFT_LINE_INPUT_3_4_VOLUME ; 
 int /*<<< orphan*/  WM8993_LEFT_OPGA_VOLUME ; 
 int /*<<< orphan*/  WM8993_LEFT_OUTPUT_VOLUME ; 
 int WM8993_MIXOUTL_ZC ; 
 int WM8993_MIXOUTR_ZC ; 
 int WM8993_MIXOUT_VU ; 
 int /*<<< orphan*/  WM8993_RIGHT_LINE_INPUT_1_2_VOLUME ; 
 int /*<<< orphan*/  WM8993_RIGHT_LINE_INPUT_3_4_VOLUME ; 
 int /*<<< orphan*/  WM8993_RIGHT_OPGA_VOLUME ; 
 int /*<<< orphan*/  WM8993_RIGHT_OUTPUT_VOLUME ; 
 int /*<<< orphan*/  WM8993_SPEAKER_VOLUME_LEFT ; 
 int /*<<< orphan*/  WM8993_SPEAKER_VOLUME_RIGHT ; 
 int WM8993_SPKOUT_VU ; 
 int /*<<< orphan*/  analogue_dapm_widgets ; 
 int /*<<< orphan*/  analogue_snd_controls ; 
 int /*<<< orphan*/  snd_soc_add_component_controls (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct snd_soc_dapm_context* snd_soc_component_get_dapm (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_soc_dapm_new_controls (struct snd_soc_dapm_context*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int wm_hubs_add_analogue_controls(struct snd_soc_component *component)
{
	struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(component);

	/* Latch volume update bits & default ZC on */
	snd_soc_component_update_bits(component, WM8993_LEFT_LINE_INPUT_1_2_VOLUME,
			    WM8993_IN1_VU, WM8993_IN1_VU);
	snd_soc_component_update_bits(component, WM8993_RIGHT_LINE_INPUT_1_2_VOLUME,
			    WM8993_IN1_VU, WM8993_IN1_VU);
	snd_soc_component_update_bits(component, WM8993_LEFT_LINE_INPUT_3_4_VOLUME,
			    WM8993_IN2_VU, WM8993_IN2_VU);
	snd_soc_component_update_bits(component, WM8993_RIGHT_LINE_INPUT_3_4_VOLUME,
			    WM8993_IN2_VU, WM8993_IN2_VU);

	snd_soc_component_update_bits(component, WM8993_SPEAKER_VOLUME_LEFT,
			    WM8993_SPKOUT_VU, WM8993_SPKOUT_VU);
	snd_soc_component_update_bits(component, WM8993_SPEAKER_VOLUME_RIGHT,
			    WM8993_SPKOUT_VU, WM8993_SPKOUT_VU);

	snd_soc_component_update_bits(component, WM8993_LEFT_OUTPUT_VOLUME,
			    WM8993_HPOUT1_VU | WM8993_HPOUT1L_ZC,
			    WM8993_HPOUT1_VU | WM8993_HPOUT1L_ZC);
	snd_soc_component_update_bits(component, WM8993_RIGHT_OUTPUT_VOLUME,
			    WM8993_HPOUT1_VU | WM8993_HPOUT1R_ZC,
			    WM8993_HPOUT1_VU | WM8993_HPOUT1R_ZC);

	snd_soc_component_update_bits(component, WM8993_LEFT_OPGA_VOLUME,
			    WM8993_MIXOUTL_ZC | WM8993_MIXOUT_VU,
			    WM8993_MIXOUTL_ZC | WM8993_MIXOUT_VU);
	snd_soc_component_update_bits(component, WM8993_RIGHT_OPGA_VOLUME,
			    WM8993_MIXOUTR_ZC | WM8993_MIXOUT_VU,
			    WM8993_MIXOUTR_ZC | WM8993_MIXOUT_VU);

	snd_soc_add_component_controls(component, analogue_snd_controls,
			     ARRAY_SIZE(analogue_snd_controls));

	snd_soc_dapm_new_controls(dapm, analogue_dapm_widgets,
				  ARRAY_SIZE(analogue_dapm_widgets));
	return 0;
}