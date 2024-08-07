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
typedef  int /*<<< orphan*/  u16 ;
struct dvb_frontend {struct dib7000p_state* demodulator_priv; } ;
struct dib7000p_state {int dummy; } ;

/* Variables and functions */
 int dib7000p_write_word (struct dib7000p_state*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int dib7000p_set_agc1_min(struct dvb_frontend *fe, u16 v)
{
	struct dib7000p_state *state = fe->demodulator_priv;
	return dib7000p_write_word(state, 108,  v);
}