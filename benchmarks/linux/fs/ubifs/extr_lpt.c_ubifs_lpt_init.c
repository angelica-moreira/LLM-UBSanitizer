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
struct ubifs_info {int dummy; } ;

/* Variables and functions */
 int lpt_init_rd (struct ubifs_info*) ; 
 int lpt_init_wr (struct ubifs_info*) ; 
 int /*<<< orphan*/  ubifs_lpt_free (struct ubifs_info*,int) ; 

int ubifs_lpt_init(struct ubifs_info *c, int rd, int wr)
{
	int err;

	if (rd) {
		err = lpt_init_rd(c);
		if (err)
			goto out_err;
	}

	if (wr) {
		err = lpt_init_wr(c);
		if (err)
			goto out_err;
	}

	return 0;

out_err:
	if (wr)
		ubifs_lpt_free(c, 1);
	if (rd)
		ubifs_lpt_free(c, 0);
	return err;
}