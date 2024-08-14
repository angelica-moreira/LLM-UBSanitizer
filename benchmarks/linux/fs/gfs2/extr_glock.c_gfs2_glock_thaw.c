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
struct gfs2_sbd {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  glock_hash_walk (int /*<<< orphan*/ ,struct gfs2_sbd*) ; 
 int /*<<< orphan*/  thaw_glock ; 

void gfs2_glock_thaw(struct gfs2_sbd *sdp)
{
	glock_hash_walk(thaw_glock, sdp);
}