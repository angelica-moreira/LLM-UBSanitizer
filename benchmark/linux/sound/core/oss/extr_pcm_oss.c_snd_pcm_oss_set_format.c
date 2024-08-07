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
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; } ;
struct TYPE_2__ {int format; int params; } ;
struct snd_pcm_runtime {TYPE_1__ oss; } ;
struct snd_pcm_oss_file {struct snd_pcm_substream** streams; } ;

/* Variables and functions */
 int AFMT_QUERY ; 
 int AFMT_U8 ; 
 int lock_params (struct snd_pcm_runtime*) ; 
 int snd_pcm_oss_get_format (struct snd_pcm_oss_file*) ; 
 int snd_pcm_oss_get_formats (struct snd_pcm_oss_file*) ; 
 int /*<<< orphan*/  unlock_params (struct snd_pcm_runtime*) ; 

__attribute__((used)) static int snd_pcm_oss_set_format(struct snd_pcm_oss_file *pcm_oss_file, int format)
{
	int formats, idx;
	int err;
	
	if (format != AFMT_QUERY) {
		formats = snd_pcm_oss_get_formats(pcm_oss_file);
		if (formats < 0)
			return formats;
		if (!(formats & format))
			format = AFMT_U8;
		for (idx = 1; idx >= 0; --idx) {
			struct snd_pcm_substream *substream = pcm_oss_file->streams[idx];
			struct snd_pcm_runtime *runtime;
			if (substream == NULL)
				continue;
			runtime = substream->runtime;
			err = lock_params(runtime);
			if (err < 0)
				return err;
			if (runtime->oss.format != format) {
				runtime->oss.params = 1;
				runtime->oss.format = format;
			}
			unlock_params(runtime);
		}
	}
	return snd_pcm_oss_get_format(pcm_oss_file);
}