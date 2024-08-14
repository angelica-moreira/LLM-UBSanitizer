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
struct hda_conn_list {int len; int /*<<< orphan*/ * conns; } ;
struct hda_codec {int dummy; } ;
typedef  int /*<<< orphan*/  hda_nid_t ;

/* Variables and functions */
 int EINVAL ; 
 struct hda_conn_list* lookup_conn_list (struct hda_codec*,int /*<<< orphan*/ ) ; 
 int read_and_add_raw_conns (struct hda_codec*,int /*<<< orphan*/ ) ; 
 scalar_t__ snd_BUG_ON (int) ; 

int snd_hda_get_conn_list(struct hda_codec *codec, hda_nid_t nid,
			  const hda_nid_t **listp)
{
	bool added = false;

	for (;;) {
		int err;
		const struct hda_conn_list *p;

		/* if the connection-list is already cached, read it */
		p = lookup_conn_list(codec, nid);
		if (p) {
			if (listp)
				*listp = p->conns;
			return p->len;
		}
		if (snd_BUG_ON(added))
			return -EINVAL;

		err = read_and_add_raw_conns(codec, nid);
		if (err < 0)
			return err;
		added = true;
	}
}