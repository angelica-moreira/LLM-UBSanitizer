#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct snd_pcm_substream {int dummy; } ;
struct TYPE_2__ {int hw_ready; } ;
struct snd_ml403_ac97cr {int enable_irq; int /*<<< orphan*/  irq; TYPE_1__ ind_rec; } ;

/* Variables and functions */
 int /*<<< orphan*/  CR_PLAYRESET ; 
 int /*<<< orphan*/  CR_REG (struct snd_ml403_ac97cr*,int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int /*<<< orphan*/  PDEBUG (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  RESETFIFO ; 
#define  SNDRV_PCM_TRIGGER_START 129 
#define  SNDRV_PCM_TRIGGER_STOP 128 
 int /*<<< orphan*/  WORK_INFO ; 
 int /*<<< orphan*/  disable_irq_nosync (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  out_be32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_pcm_indirect2_stat (struct snd_pcm_substream*,TYPE_1__*) ; 
 struct snd_ml403_ac97cr* snd_pcm_substream_chip (struct snd_pcm_substream*) ; 

__attribute__((used)) static int
snd_ml403_ac97cr_pcm_playback_trigger(struct snd_pcm_substream *substream,
				      int cmd)
{
	struct snd_ml403_ac97cr *ml403_ac97cr;
	int err = 0;

	ml403_ac97cr = snd_pcm_substream_chip(substream);

	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
		PDEBUG(WORK_INFO, "trigger(playback): START\n");
		ml403_ac97cr->ind_rec.hw_ready = 1;

		/* clear play FIFO */
		out_be32(CR_REG(ml403_ac97cr, RESETFIFO), CR_PLAYRESET);

		/* enable play irq */
		ml403_ac97cr->enable_irq = 1;
		enable_irq(ml403_ac97cr->irq);
		break;
	case SNDRV_PCM_TRIGGER_STOP:
		PDEBUG(WORK_INFO, "trigger(playback): STOP\n");
		ml403_ac97cr->ind_rec.hw_ready = 0;
#ifdef SND_PCM_INDIRECT2_STAT
		snd_pcm_indirect2_stat(substream, &ml403_ac97cr->ind_rec);
#endif
		/* disable play irq */
		disable_irq_nosync(ml403_ac97cr->irq);
		ml403_ac97cr->enable_irq = 0;
		break;
	default:
		err = -EINVAL;
		break;
	}
	PDEBUG(WORK_INFO, "trigger(playback): (done)\n");
	return err;
}