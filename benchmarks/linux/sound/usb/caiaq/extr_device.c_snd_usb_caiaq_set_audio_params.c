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
typedef  int /*<<< orphan*/  tmp ;
struct snd_usb_caiaqdev {int audio_parm_answer; int bpp; int /*<<< orphan*/  ep1_wait_queue; } ;
struct device {int dummy; } ;

/* Variables and functions */
 char DEPTH_16 ; 
 char DEPTH_24 ; 
 int EINVAL ; 
 int /*<<< orphan*/  EP1_CMD_AUDIO_PARAMS ; 
 int EPIPE ; 
 int /*<<< orphan*/  HZ ; 
 char SAMPLERATE_192000 ; 
 char SAMPLERATE_44100 ; 
 char SAMPLERATE_48000 ; 
 char SAMPLERATE_88200 ; 
 char SAMPLERATE_96000 ; 
 struct device* caiaqdev_to_dev (struct snd_usb_caiaqdev*) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int snd_usb_caiaq_send_command (struct snd_usb_caiaqdev*,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  wait_event_timeout (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

int snd_usb_caiaq_set_audio_params (struct snd_usb_caiaqdev *cdev,
		   		    int rate, int depth, int bpp)
{
	int ret;
	char tmp[5];
	struct device *dev = caiaqdev_to_dev(cdev);

	switch (rate) {
	case 44100:	tmp[0] = SAMPLERATE_44100;   break;
	case 48000:	tmp[0] = SAMPLERATE_48000;   break;
	case 88200:	tmp[0] = SAMPLERATE_88200;   break;
	case 96000:	tmp[0] = SAMPLERATE_96000;   break;
	case 192000:	tmp[0] = SAMPLERATE_192000;  break;
	default:	return -EINVAL;
	}

	switch (depth) {
	case 16:	tmp[1] = DEPTH_16;   break;
	case 24:	tmp[1] = DEPTH_24;   break;
	default:	return -EINVAL;
	}

	tmp[2] = bpp & 0xff;
	tmp[3] = bpp >> 8;
	tmp[4] = 1; /* packets per microframe */

	dev_dbg(dev, "setting audio params: %d Hz, %d bits, %d bpp\n",
		rate, depth, bpp);

	cdev->audio_parm_answer = -1;
	ret = snd_usb_caiaq_send_command(cdev, EP1_CMD_AUDIO_PARAMS,
					 tmp, sizeof(tmp));

	if (ret)
		return ret;

	if (!wait_event_timeout(cdev->ep1_wait_queue,
	    cdev->audio_parm_answer >= 0, HZ))
		return -EPIPE;

	if (cdev->audio_parm_answer != 1)
		dev_dbg(dev, "unable to set the device's audio params\n");
	else
		cdev->bpp = bpp;

	return cdev->audio_parm_answer == 1 ? 0 : -EINVAL;
}