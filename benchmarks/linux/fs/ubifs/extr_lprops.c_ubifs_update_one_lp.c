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
struct ubifs_lprops {int flags; scalar_t__ dirty; } ;
struct ubifs_info {int dummy; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct ubifs_lprops const*) ; 
 int PTR_ERR (struct ubifs_lprops const*) ; 
 struct ubifs_lprops* ubifs_change_lp (struct ubifs_info*,struct ubifs_lprops const*,int,scalar_t__,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ubifs_err (struct ubifs_info*,char*,int,int) ; 
 int /*<<< orphan*/  ubifs_get_lprops (struct ubifs_info*) ; 
 struct ubifs_lprops* ubifs_lpt_lookup_dirty (struct ubifs_info*,int) ; 
 int /*<<< orphan*/  ubifs_release_lprops (struct ubifs_info*) ; 

int ubifs_update_one_lp(struct ubifs_info *c, int lnum, int free, int dirty,
			int flags_set, int flags_clean)
{
	int err = 0, flags;
	const struct ubifs_lprops *lp;

	ubifs_get_lprops(c);

	lp = ubifs_lpt_lookup_dirty(c, lnum);
	if (IS_ERR(lp)) {
		err = PTR_ERR(lp);
		goto out;
	}

	flags = (lp->flags | flags_set) & ~flags_clean;
	lp = ubifs_change_lp(c, lp, free, lp->dirty + dirty, flags, 0);
	if (IS_ERR(lp))
		err = PTR_ERR(lp);

out:
	ubifs_release_lprops(c);
	if (err)
		ubifs_err(c, "cannot update properties of LEB %d, error %d",
			  lnum, err);
	return err;
}