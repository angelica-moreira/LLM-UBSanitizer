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
struct snd_motu {int /*<<< orphan*/  card; } ;
struct snd_info_entry {int dummy; } ;

/* Variables and functions */
 struct snd_info_entry* snd_info_create_card_entry (int /*<<< orphan*/ ,char const*,struct snd_info_entry*) ; 
 int /*<<< orphan*/  snd_info_set_text_ops (struct snd_info_entry*,struct snd_motu*,void (*) (struct snd_info_entry*,struct snd_info_buffer*)) ; 

__attribute__((used)) static void add_node(struct snd_motu *motu, struct snd_info_entry *root,
		     const char *name,
		     void (*op)(struct snd_info_entry *e,
				struct snd_info_buffer *b))
{
	struct snd_info_entry *entry;

	entry = snd_info_create_card_entry(motu->card, name, root);
	if (entry)
		snd_info_set_text_ops(entry, motu, op);
}