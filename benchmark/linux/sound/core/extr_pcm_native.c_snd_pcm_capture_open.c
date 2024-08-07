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
struct snd_pcm {int /*<<< orphan*/  card; } ;
struct inode {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SNDRV_DEVICE_TYPE_PCM_CAPTURE ; 
 int /*<<< orphan*/  SNDRV_PCM_STREAM_CAPTURE ; 
 int /*<<< orphan*/  iminor (struct inode*) ; 
 int nonseekable_open (struct inode*,struct file*) ; 
 int /*<<< orphan*/  snd_card_unref (int /*<<< orphan*/ ) ; 
 struct snd_pcm* snd_lookup_minor_data (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_pcm_open (struct file*,struct snd_pcm*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int snd_pcm_capture_open(struct inode *inode, struct file *file)
{
	struct snd_pcm *pcm;
	int err = nonseekable_open(inode, file);
	if (err < 0)
		return err;
	pcm = snd_lookup_minor_data(iminor(inode),
				    SNDRV_DEVICE_TYPE_PCM_CAPTURE);
	err = snd_pcm_open(file, pcm, SNDRV_PCM_STREAM_CAPTURE);
	if (pcm)
		snd_card_unref(pcm->card);
	return err;
}