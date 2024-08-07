#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {int channels; int rate; int /*<<< orphan*/  dma_addr; int /*<<< orphan*/  format; } ;
struct TYPE_4__ {unsigned int size; int reg; int /*<<< orphan*/  addr; } ;
struct snd_ad1889 {TYPE_2__ wave; TYPE_1__* card; int /*<<< orphan*/  lock; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  AD_CHAN_WAV ; 
 int /*<<< orphan*/  AD_DS_WAS ; 
 int /*<<< orphan*/  AD_DS_WSMC ; 
 int AD_DS_WSMC_WA16 ; 
 int AD_DS_WSMC_WAST ; 
 int /*<<< orphan*/  ad1889_channel_reset (struct snd_ad1889*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ad1889_load_wave_buffer_address (struct snd_ad1889*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ad1889_load_wave_buffer_count (struct snd_ad1889*,unsigned int) ; 
 int /*<<< orphan*/  ad1889_load_wave_interrupt_count (struct snd_ad1889*,unsigned int) ; 
 int ad1889_readw (struct snd_ad1889*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ad1889_writew (struct snd_ad1889*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,unsigned int,unsigned int,int,int) ; 
 int snd_pcm_format_width (int /*<<< orphan*/ ) ; 
 unsigned int snd_pcm_lib_buffer_bytes (struct snd_pcm_substream*) ; 
 unsigned int snd_pcm_lib_period_bytes (struct snd_pcm_substream*) ; 
 struct snd_ad1889* snd_pcm_substream_chip (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
snd_ad1889_playback_prepare(struct snd_pcm_substream *ss)
{
	struct snd_ad1889 *chip = snd_pcm_substream_chip(ss);
	struct snd_pcm_runtime *rt = ss->runtime;
	unsigned int size = snd_pcm_lib_buffer_bytes(ss);
	unsigned int count = snd_pcm_lib_period_bytes(ss);
	u16 reg;

	ad1889_channel_reset(chip, AD_CHAN_WAV);

	reg = ad1889_readw(chip, AD_DS_WSMC);
	
	/* Mask out 16-bit / Stereo */
	reg &= ~(AD_DS_WSMC_WA16 | AD_DS_WSMC_WAST);

	if (snd_pcm_format_width(rt->format) == 16)
		reg |= AD_DS_WSMC_WA16;

	if (rt->channels > 1)
		reg |= AD_DS_WSMC_WAST;

	/* let's make sure we don't clobber ourselves */
	spin_lock_irq(&chip->lock);
	
	chip->wave.size = size;
	chip->wave.reg = reg;
	chip->wave.addr = rt->dma_addr;

	ad1889_writew(chip, AD_DS_WSMC, chip->wave.reg);
	
	/* Set sample rates on the codec */
	ad1889_writew(chip, AD_DS_WAS, rt->rate);

	/* Set up DMA */
	ad1889_load_wave_buffer_address(chip, chip->wave.addr);
	ad1889_load_wave_buffer_count(chip, size);
	ad1889_load_wave_interrupt_count(chip, count);

	/* writes flush */
	ad1889_readw(chip, AD_DS_WSMC);
	
	spin_unlock_irq(&chip->lock);
	
	dev_dbg(chip->card->dev,
		"prepare playback: addr = 0x%x, count = %u, size = %u, reg = 0x%x, rate = %u\n",
		chip->wave.addr, count, size, reg, rt->rate);
	return 0;
}