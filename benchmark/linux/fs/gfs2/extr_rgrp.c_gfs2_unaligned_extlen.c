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
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u32 ;
struct gfs2_rbm {int dummy; } ;

/* Variables and functions */
 scalar_t__ GFS2_BLKST_FREE ; 
 scalar_t__ gfs2_rbm_incr (struct gfs2_rbm*) ; 
 scalar_t__ gfs2_testbit (struct gfs2_rbm*,int) ; 

__attribute__((used)) static bool gfs2_unaligned_extlen(struct gfs2_rbm *rbm, u32 n_unaligned, u32 *len)
{
	u32 n;
	u8 res;

	for (n = 0; n < n_unaligned; n++) {
		res = gfs2_testbit(rbm, true);
		if (res != GFS2_BLKST_FREE)
			return true;
		(*len)--;
		if (*len == 0)
			return true;
		if (gfs2_rbm_incr(rbm))
			return true;
	}

	return false;
}