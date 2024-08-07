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
struct gfs2_glock {int dummy; } ;
struct buffer_head {int /*<<< orphan*/  b_end_io; } ;
typedef  int /*<<< orphan*/  const __be64 ;

/* Variables and functions */
 int /*<<< orphan*/  CREATE ; 
 int REQ_META ; 
 int /*<<< orphan*/  REQ_OP_READ ; 
 int REQ_PRIO ; 
 int REQ_RAHEAD ; 
 int /*<<< orphan*/  be64_to_cpu (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  brelse (struct buffer_head*) ; 
 int /*<<< orphan*/  buffer_uptodate (struct buffer_head*) ; 
 int /*<<< orphan*/  end_buffer_read_sync ; 
 struct buffer_head* gfs2_getbuf (struct gfs2_glock*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  submit_bh (int /*<<< orphan*/ ,int,struct buffer_head*) ; 
 scalar_t__ trylock_buffer (struct buffer_head*) ; 
 int /*<<< orphan*/  unlock_buffer (struct buffer_head*) ; 

__attribute__((used)) static void gfs2_metapath_ra(struct gfs2_glock *gl, __be64 *start, __be64 *end)
{
	const __be64 *t;

	for (t = start; t < end; t++) {
		struct buffer_head *rabh;

		if (!*t)
			continue;

		rabh = gfs2_getbuf(gl, be64_to_cpu(*t), CREATE);
		if (trylock_buffer(rabh)) {
			if (!buffer_uptodate(rabh)) {
				rabh->b_end_io = end_buffer_read_sync;
				submit_bh(REQ_OP_READ,
					  REQ_RAHEAD | REQ_META | REQ_PRIO,
					  rabh);
				continue;
			}
			unlock_buffer(rabh);
		}
		brelse(rabh);
	}
}