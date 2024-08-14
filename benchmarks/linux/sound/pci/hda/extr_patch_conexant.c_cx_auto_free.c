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
 int /*<<< orphan*/  cx_auto_reboot_notify (struct hda_codec*) ; 
 int /*<<< orphan*/  snd_hda_gen_free (struct hda_codec*) ; 

__attribute__((used)) static void cx_auto_free(struct hda_codec *codec)
{
	cx_auto_reboot_notify(codec);
	snd_hda_gen_free(codec);
}