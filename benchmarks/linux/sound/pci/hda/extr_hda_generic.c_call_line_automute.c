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
struct hda_jack_callback {int dummy; } ;
struct hda_gen_spec {int /*<<< orphan*/  (* line_automute_hook ) (struct hda_codec*,struct hda_jack_callback*) ;} ;
struct hda_codec {struct hda_gen_spec* spec; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_hda_gen_line_automute (struct hda_codec*,struct hda_jack_callback*) ; 
 int /*<<< orphan*/  stub1 (struct hda_codec*,struct hda_jack_callback*) ; 

__attribute__((used)) static void call_line_automute(struct hda_codec *codec,
			       struct hda_jack_callback *jack)
{
	struct hda_gen_spec *spec = codec->spec;
	if (spec->line_automute_hook)
		spec->line_automute_hook(codec, jack);
	else
		snd_hda_gen_line_automute(codec, jack);
}