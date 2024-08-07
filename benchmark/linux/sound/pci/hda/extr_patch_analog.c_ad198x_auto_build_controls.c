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
struct hda_codec {int dummy; } ;

/* Variables and functions */
 int create_beep_ctls (struct hda_codec*) ; 
 int snd_hda_gen_build_controls (struct hda_codec*) ; 

__attribute__((used)) static int ad198x_auto_build_controls(struct hda_codec *codec)
{
	int err;

	err = snd_hda_gen_build_controls(codec);
	if (err < 0)
		return err;
	err = create_beep_ctls(codec);
	if (err < 0)
		return err;
	return 0;
}