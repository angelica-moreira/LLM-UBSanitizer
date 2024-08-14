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
struct snd_pcm_substream {int dummy; } ;
struct oxygen {unsigned int interrupt_mask; int /*<<< orphan*/  reg_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  OXYGEN_DMA_FLUSH ; 
 int /*<<< orphan*/  OXYGEN_INTERRUPT_MASK ; 
 int /*<<< orphan*/  oxygen_clear_bits8 (struct oxygen*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  oxygen_set_bits8 (struct oxygen*,int /*<<< orphan*/ ,unsigned int) ; 
 unsigned int oxygen_substream_channel (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  oxygen_write16 (struct oxygen*,int /*<<< orphan*/ ,unsigned int) ; 
 int snd_pcm_lib_free_pages (struct snd_pcm_substream*) ; 
 struct oxygen* snd_pcm_substream_chip (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int oxygen_hw_free(struct snd_pcm_substream *substream)
{
	struct oxygen *chip = snd_pcm_substream_chip(substream);
	unsigned int channel = oxygen_substream_channel(substream);
	unsigned int channel_mask = 1 << channel;

	spin_lock_irq(&chip->reg_lock);
	chip->interrupt_mask &= ~channel_mask;
	oxygen_write16(chip, OXYGEN_INTERRUPT_MASK, chip->interrupt_mask);

	oxygen_set_bits8(chip, OXYGEN_DMA_FLUSH, channel_mask);
	oxygen_clear_bits8(chip, OXYGEN_DMA_FLUSH, channel_mask);
	spin_unlock_irq(&chip->reg_lock);

	return snd_pcm_lib_free_pages(substream);
}