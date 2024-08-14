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
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {int /*<<< orphan*/  dma_addr; int /*<<< orphan*/  channels; int /*<<< orphan*/  format; int /*<<< orphan*/  rate; struct snd_azf3328_codec_data* private_data; } ;
struct snd_azf3328_codec_data {int /*<<< orphan*/  dma_base; } ;

/* Variables and functions */
 int /*<<< orphan*/  chip ; 
 int /*<<< orphan*/  snd_azf3328_codec_setdmaa (int /*<<< orphan*/ ,struct snd_azf3328_codec_data*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  snd_azf3328_codec_setfmt (struct snd_azf3328_codec_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_pcm_format_width (int /*<<< orphan*/ ) ; 
 unsigned int snd_pcm_lib_buffer_bytes (struct snd_pcm_substream*) ; 
 unsigned int snd_pcm_lib_period_bytes (struct snd_pcm_substream*) ; 

__attribute__((used)) static int
snd_azf3328_pcm_prepare(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct snd_azf3328_codec_data *codec = runtime->private_data;
#if 0
        unsigned int size = snd_pcm_lib_buffer_bytes(substream);
	unsigned int count = snd_pcm_lib_period_bytes(substream);
#endif

	codec->dma_base = runtime->dma_addr;

#if 0
	snd_azf3328_codec_setfmt(codec,
		runtime->rate,
		snd_pcm_format_width(runtime->format),
		runtime->channels);
	snd_azf3328_codec_setdmaa(chip, codec,
					runtime->dma_addr, count, size);
#endif
	return 0;
}