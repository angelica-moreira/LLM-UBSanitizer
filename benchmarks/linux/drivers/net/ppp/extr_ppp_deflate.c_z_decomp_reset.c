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
struct ppp_deflate_state {int /*<<< orphan*/  strm; scalar_t__ seqno; } ;

/* Variables and functions */
 int /*<<< orphan*/  zlib_inflateReset (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void z_decomp_reset(void *arg)
{
	struct ppp_deflate_state *state = (struct ppp_deflate_state *) arg;

	state->seqno = 0;
	zlib_inflateReset(&state->strm);
}