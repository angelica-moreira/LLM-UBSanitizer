#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct snd_pcm_chmap {struct hdac_chmap* private_data; } ;
struct snd_kcontrol {int private_value; } ;
struct TYPE_5__ {unsigned char* value; } ;
struct TYPE_6__ {TYPE_2__ integer; } ;
struct snd_ctl_elem_value {TYPE_3__ value; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* get_chmap ) (int /*<<< orphan*/ ,int,unsigned char*) ;} ;
struct hdac_chmap {int /*<<< orphan*/  hdac; TYPE_1__ ops; } ;
typedef  int /*<<< orphan*/  pcm_chmap ;

/* Variables and functions */
 int ARRAY_SIZE (unsigned char*) ; 
 int /*<<< orphan*/  memset (unsigned char*,int /*<<< orphan*/ ,int) ; 
 struct snd_pcm_chmap* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int,unsigned char*) ; 

__attribute__((used)) static int hdmi_chmap_ctl_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *ucontrol)
{
	struct snd_pcm_chmap *info = snd_kcontrol_chip(kcontrol);
	struct hdac_chmap *chmap = info->private_data;
	int pcm_idx = kcontrol->private_value;
	unsigned char pcm_chmap[8];
	int i;

	memset(pcm_chmap, 0, sizeof(pcm_chmap));
	chmap->ops.get_chmap(chmap->hdac, pcm_idx, pcm_chmap);

	for (i = 0; i < ARRAY_SIZE(pcm_chmap); i++)
		ucontrol->value.integer.value[i] = pcm_chmap[i];

	return 0;
}