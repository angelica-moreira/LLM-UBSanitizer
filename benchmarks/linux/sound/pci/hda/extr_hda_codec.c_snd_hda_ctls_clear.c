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
struct hda_nid_item {int /*<<< orphan*/  kctl; } ;
struct TYPE_2__ {int used; struct hda_nid_item* list; } ;
struct hda_codec {TYPE_1__ nids; TYPE_1__ mixers; int /*<<< orphan*/  card; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_array_free (TYPE_1__*) ; 
 int /*<<< orphan*/  snd_ctl_remove (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void snd_hda_ctls_clear(struct hda_codec *codec)
{
	int i;
	struct hda_nid_item *items = codec->mixers.list;
	for (i = 0; i < codec->mixers.used; i++)
		snd_ctl_remove(codec->card, items[i].kctl);
	snd_array_free(&codec->mixers);
	snd_array_free(&codec->nids);
}