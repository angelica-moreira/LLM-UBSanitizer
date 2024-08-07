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
typedef  int u16 ;
struct dib0090_state {int const* bb_ramp; } ;

/* Variables and functions */
 int /*<<< orphan*/  dib0090_set_boost (struct dib0090_state*,int) ; 

__attribute__((used)) static void dib0090_set_bbramp(struct dib0090_state *state, const u16 * cfg)
{
	state->bb_ramp = cfg;
	dib0090_set_boost(state, cfg[0] > 500);	/* we want the boost if the gain is higher that 50dB */
}