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
struct dvb_frontend {struct cx22700_state* demodulator_priv; } ;
struct cx22700_state {int dummy; } ;

/* Variables and functions */
 int cx22700_writereg (struct cx22700_state*,int,int) ; 

__attribute__((used)) static int cx22700_i2c_gate_ctrl(struct dvb_frontend* fe, int enable)
{
	struct cx22700_state* state = fe->demodulator_priv;

	if (enable) {
		return cx22700_writereg(state, 0x0a, 0x00);
	} else {
		return cx22700_writereg(state, 0x0a, 0x01);
	}
}