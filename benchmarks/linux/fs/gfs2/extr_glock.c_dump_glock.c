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
struct seq_file {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  lock; } ;
struct gfs2_glock {TYPE_1__ gl_lockref; } ;

/* Variables and functions */
 int /*<<< orphan*/  gfs2_dump_glock (struct seq_file*,struct gfs2_glock*,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void dump_glock(struct seq_file *seq, struct gfs2_glock *gl, bool fsid)
{
	spin_lock(&gl->gl_lockref.lock);
	gfs2_dump_glock(seq, gl, fsid);
	spin_unlock(&gl->gl_lockref.lock);
}