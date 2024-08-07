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
 scalar_t__ codec_probed (struct hda_codec*) ; 
 int /*<<< orphan*/  request_codec_module (struct hda_codec*) ; 

__attribute__((used)) static void codec_bind_module(struct hda_codec *codec)
{
#ifdef MODULE
	request_codec_module(codec);
	if (codec_probed(codec))
		return;
#endif
}