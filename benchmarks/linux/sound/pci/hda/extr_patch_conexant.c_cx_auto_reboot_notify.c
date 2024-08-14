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
struct hda_codec {struct conexant_spec* spec; } ;
struct conexant_spec {int /*<<< orphan*/  eapds; int /*<<< orphan*/  num_eapds; } ;

/* Variables and functions */
 int /*<<< orphan*/  cx_auto_turn_eapd (struct hda_codec*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snd_hda_gen_reboot_notify (struct hda_codec*) ; 

__attribute__((used)) static void cx_auto_reboot_notify(struct hda_codec *codec)
{
	struct conexant_spec *spec = codec->spec;

	/* Turn the problematic codec into D3 to avoid spurious noises
	   from the internal speaker during (and after) reboot */
	cx_auto_turn_eapd(codec, spec->num_eapds, spec->eapds, false);
	snd_hda_gen_reboot_notify(codec);
}