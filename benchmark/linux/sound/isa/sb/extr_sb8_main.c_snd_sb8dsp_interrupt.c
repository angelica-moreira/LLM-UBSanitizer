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
struct snd_sb {int mode; int /*<<< orphan*/  capture_format; struct snd_pcm_substream* capture_substream; int /*<<< orphan*/  hardware; int /*<<< orphan*/  playback_format; struct snd_pcm_substream* playback_substream; } ;
struct snd_pcm_substream {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  SB_DSP_INPUT ; 
 int /*<<< orphan*/  SB_DSP_OUTPUT ; 
 int /*<<< orphan*/  SB_HW_JAZZ16 ; 
#define  SB_MODE_CAPTURE_16 131 
#define  SB_MODE_CAPTURE_8 130 
#define  SB_MODE_PLAYBACK_16 129 
#define  SB_MODE_PLAYBACK_8 128 
 int /*<<< orphan*/  SNDRV_PCM_TRIGGER_START ; 
 int /*<<< orphan*/  snd_pcm_period_elapsed (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  snd_sb8_capture_trigger (struct snd_pcm_substream*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_sb8_playback_trigger (struct snd_pcm_substream*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_sb_ack_8bit (struct snd_sb*) ; 

irqreturn_t snd_sb8dsp_interrupt(struct snd_sb *chip)
{
	struct snd_pcm_substream *substream;

	snd_sb_ack_8bit(chip);
	switch (chip->mode) {
	case SB_MODE_PLAYBACK_16:	/* ok.. playback is active */
		if (chip->hardware != SB_HW_JAZZ16)
			break;
		/* fall through */
	case SB_MODE_PLAYBACK_8:
		substream = chip->playback_substream;
		if (chip->playback_format == SB_DSP_OUTPUT)
		    	snd_sb8_playback_trigger(substream, SNDRV_PCM_TRIGGER_START);
		snd_pcm_period_elapsed(substream);
		break;
	case SB_MODE_CAPTURE_16:
		if (chip->hardware != SB_HW_JAZZ16)
			break;
		/* fall through */
	case SB_MODE_CAPTURE_8:
		substream = chip->capture_substream;
		if (chip->capture_format == SB_DSP_INPUT)
		    	snd_sb8_capture_trigger(substream, SNDRV_PCM_TRIGGER_START);
		snd_pcm_period_elapsed(substream);
		break;
	}
	return IRQ_HANDLED;
}