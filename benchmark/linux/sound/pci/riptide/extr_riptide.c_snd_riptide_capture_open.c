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
struct snd_riptide {struct snd_pcm_substream* capture_substream; } ;
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {struct pcmhw* private_data; int /*<<< orphan*/  hw; } ;
struct pcmhw {int* intdec; int /*<<< orphan*/  state; int /*<<< orphan*/  source; int /*<<< orphan*/  id; int /*<<< orphan*/  paths; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACLNK2PADC ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  PADC ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_PERIODS ; 
 int /*<<< orphan*/  ST_STOP ; 
 struct pcmhw* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lbus_rec_path ; 
 int snd_pcm_hw_constraint_integer (struct snd_pcm_runtime*,int /*<<< orphan*/ ) ; 
 struct snd_riptide* snd_pcm_substream_chip (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  snd_riptide_capture ; 

__attribute__((used)) static int snd_riptide_capture_open(struct snd_pcm_substream *substream)
{
	struct snd_riptide *chip = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct pcmhw *data;

	chip->capture_substream = substream;
	runtime->hw = snd_riptide_capture;

	data = kzalloc(sizeof(struct pcmhw), GFP_KERNEL);
	if (data == NULL)
		return -ENOMEM;
	data->paths = lbus_rec_path;
	data->id = PADC;
	data->source = ACLNK2PADC;
	data->intdec[0] = 0xff;
	data->intdec[1] = 0xff;
	data->state = ST_STOP;
	runtime->private_data = data;
	return snd_pcm_hw_constraint_integer(runtime,
					     SNDRV_PCM_HW_PARAM_PERIODS);
}