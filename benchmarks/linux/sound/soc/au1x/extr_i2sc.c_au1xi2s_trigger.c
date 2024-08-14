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
struct snd_soc_dai {int dummy; } ;
struct snd_pcm_substream {int dummy; } ;
struct au1xpsc_audio_data {int cfg; } ;

/* Variables and functions */
 int CFG_RN ; 
 int CFG_TN ; 
 int EINVAL ; 
 int EN_CE ; 
 int EN_D ; 
 int /*<<< orphan*/  I2S_CFG ; 
 int /*<<< orphan*/  I2S_ENABLE ; 
 int PCM_TX ; 
#define  SNDRV_PCM_TRIGGER_RESUME 131 
#define  SNDRV_PCM_TRIGGER_START 130 
#define  SNDRV_PCM_TRIGGER_STOP 129 
#define  SNDRV_PCM_TRIGGER_SUSPEND 128 
 int SUBSTREAM_TYPE (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  WR (struct au1xpsc_audio_data*,int /*<<< orphan*/ ,int) ; 
 struct au1xpsc_audio_data* snd_soc_dai_get_drvdata (struct snd_soc_dai*) ; 

__attribute__((used)) static int au1xi2s_trigger(struct snd_pcm_substream *substream,
			   int cmd, struct snd_soc_dai *dai)
{
	struct au1xpsc_audio_data *ctx = snd_soc_dai_get_drvdata(dai);
	int stype = SUBSTREAM_TYPE(substream);

	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
	case SNDRV_PCM_TRIGGER_RESUME:
		/* power up */
		WR(ctx, I2S_ENABLE, EN_D | EN_CE);
		WR(ctx, I2S_ENABLE, EN_CE);
		ctx->cfg |= (stype == PCM_TX) ? CFG_TN : CFG_RN;
		WR(ctx, I2S_CFG, ctx->cfg);
		break;
	case SNDRV_PCM_TRIGGER_STOP:
	case SNDRV_PCM_TRIGGER_SUSPEND:
		ctx->cfg &= ~((stype == PCM_TX) ? CFG_TN : CFG_RN);
		WR(ctx, I2S_CFG, ctx->cfg);
		WR(ctx, I2S_ENABLE, EN_D);		/* power off */
		break;
	default:
		return -EINVAL;
	}

	return 0;
}