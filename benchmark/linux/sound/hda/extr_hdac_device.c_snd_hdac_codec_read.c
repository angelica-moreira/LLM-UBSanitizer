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
struct hdac_device {int dummy; } ;
typedef  int /*<<< orphan*/  hda_nid_t ;

/* Variables and functions */
 int codec_read (struct hdac_device*,int /*<<< orphan*/ ,int,unsigned int,unsigned int) ; 

int snd_hdac_codec_read(struct hdac_device *hdac, hda_nid_t nid,
			int flags, unsigned int verb, unsigned int parm)
{
	return codec_read(hdac, nid, flags, verb, parm);
}