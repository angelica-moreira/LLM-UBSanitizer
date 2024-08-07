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
struct snd_kcontrol_new {int /*<<< orphan*/  put; int /*<<< orphan*/  get; int /*<<< orphan*/  info; } ;
struct hda_codec {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AE5_HEADPHONE_GAIN_ENUM ; 
 struct snd_kcontrol_new HDA_CODEC_MUTE_MONO (char*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HDA_OUTPUT ; 
 int /*<<< orphan*/  ae5_headphone_gain_get ; 
 int /*<<< orphan*/  ae5_headphone_gain_info ; 
 int /*<<< orphan*/  ae5_headphone_gain_put ; 
 int /*<<< orphan*/  snd_ctl_new1 (struct snd_kcontrol_new*,struct hda_codec*) ; 
 int snd_hda_ctl_add (struct hda_codec*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ae5_add_headphone_gain_enum(struct hda_codec *codec)
{
	struct snd_kcontrol_new knew =
		HDA_CODEC_MUTE_MONO("AE-5: Headphone Gain",
				    AE5_HEADPHONE_GAIN_ENUM, 1, 0, HDA_OUTPUT);
	knew.info = ae5_headphone_gain_info;
	knew.get = ae5_headphone_gain_get;
	knew.put = ae5_headphone_gain_put;
	return snd_hda_ctl_add(codec, AE5_HEADPHONE_GAIN_ENUM,
				snd_ctl_new1(&knew, codec));
}