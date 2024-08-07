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
struct snd_sof_dev {int dummy; } ;
struct snd_pcm_substream {TYPE_1__* runtime; } ;
struct intel_stream {int dummy; } ;
struct TYPE_2__ {struct intel_stream* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct intel_stream*) ; 

int intel_pcm_close(struct snd_sof_dev *sdev,
		    struct snd_pcm_substream *substream)
{
	struct intel_stream *stream = substream->runtime->private_data;

	substream->runtime->private_data = NULL;
	kfree(stream);

	return 0;
}