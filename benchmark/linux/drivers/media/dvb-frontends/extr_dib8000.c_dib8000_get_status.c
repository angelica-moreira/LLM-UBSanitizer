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
struct dvb_frontend {struct dib8000_state* demodulator_priv; } ;
struct dib8000_state {int /*<<< orphan*/  status; } ;
typedef  int /*<<< orphan*/  s32 ;

/* Variables and functions */

__attribute__((used)) static s32 dib8000_get_status(struct dvb_frontend *fe)
{
	struct dib8000_state *state = fe->demodulator_priv;
	return state->status;
}