#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct snd_pcm_substream {int f_flags; } ;
struct snd_kcontrol {scalar_t__ private_value; } ;
struct TYPE_5__ {int* value; } ;
struct TYPE_6__ {TYPE_2__ integer; } ;
struct snd_ctl_elem_value {TYPE_3__ value; } ;
struct TYPE_4__ {struct snd_pcm_substream* capture_pcm_substream; } ;
struct em28xx {int /*<<< orphan*/  lock; scalar_t__ disconnected; TYPE_1__ adev; } ;

/* Variables and functions */
 int EAGAIN ; 
 int ENODEV ; 
 int O_NONBLOCK ; 
 int /*<<< orphan*/  dprintk (char*,char*,int,int,int,int) ; 
 int em28xx_read_ac97 (struct em28xx*,scalar_t__) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_trylock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct em28xx* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int em28xx_vol_get(struct snd_kcontrol *kcontrol,
			  struct snd_ctl_elem_value *value)
{
	struct em28xx *dev = snd_kcontrol_chip(kcontrol);
	struct snd_pcm_substream *substream = dev->adev.capture_pcm_substream;
	int nonblock = 0;
	int val;

	if (dev->disconnected)
		return -ENODEV;

	if (substream)
		nonblock = !!(substream->f_flags & O_NONBLOCK);
	if (nonblock) {
		if (!mutex_trylock(&dev->lock))
			return -EAGAIN;
	} else {
		mutex_lock(&dev->lock);
	}
	val = em28xx_read_ac97(dev, kcontrol->private_value);
	mutex_unlock(&dev->lock);
	if (val < 0)
		return val;

	dprintk("%sleft vol %d, right vol %d (0x%04x) from ac97 volume control 0x%04x\n",
		(val & 0x8000) ? "muted " : "",
		0x1f - ((val >> 8) & 0x1f), 0x1f - (val & 0x1f),
		val, (int)kcontrol->private_value);

	value->value.integer.value[0] = 0x1f - (val & 0x1f);
	value->value.integer.value[1] = 0x1f - ((val >> 8) & 0x1f);

	return 0;
}