#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct snd_pcm_substream {TYPE_2__* runtime; } ;
struct TYPE_5__ {int /*<<< orphan*/  pt; } ;
struct saa7134_dev {TYPE_1__ dmasound; int /*<<< orphan*/  pci; } ;
struct TYPE_7__ {struct saa7134_dev* dev; } ;
typedef  TYPE_3__ snd_card_saa7134_t ;
struct TYPE_6__ {int /*<<< orphan*/ * dma_area; } ;

/* Variables and functions */
 int /*<<< orphan*/  dsp_buffer_free (struct saa7134_dev*) ; 
 int /*<<< orphan*/  saa7134_alsa_dma_unmap (struct saa7134_dev*) ; 
 int /*<<< orphan*/  saa7134_pgtable_free (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 TYPE_3__* snd_pcm_substream_chip (struct snd_pcm_substream*) ; 

__attribute__((used)) static int snd_card_saa7134_hw_free(struct snd_pcm_substream * substream)
{
	snd_card_saa7134_t *saa7134 = snd_pcm_substream_chip(substream);
	struct saa7134_dev *dev;

	dev = saa7134->dev;

	if (substream->runtime->dma_area) {
		saa7134_pgtable_free(dev->pci, &dev->dmasound.pt);
		saa7134_alsa_dma_unmap(dev);
		dsp_buffer_free(dev);
		substream->runtime->dma_area = NULL;
	}

	return 0;
}