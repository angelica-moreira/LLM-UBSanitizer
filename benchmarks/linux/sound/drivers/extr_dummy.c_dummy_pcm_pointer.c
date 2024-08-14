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
struct snd_pcm_substream {int dummy; } ;
typedef  int /*<<< orphan*/  snd_pcm_uframes_t ;
struct TYPE_2__ {int /*<<< orphan*/  (* pointer ) (struct snd_pcm_substream*) ;} ;

/* Variables and functions */
 TYPE_1__* get_dummy_ops (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  stub1 (struct snd_pcm_substream*) ; 

__attribute__((used)) static snd_pcm_uframes_t dummy_pcm_pointer(struct snd_pcm_substream *substream)
{
	return get_dummy_ops(substream)->pointer(substream);
}