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
struct tda10021_state {int dummy; } ;
struct dvb_frontend {struct tda10021_state* demodulator_priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  lock_tuner (struct tda10021_state*) ; 
 int /*<<< orphan*/  unlock_tuner (struct tda10021_state*) ; 

__attribute__((used)) static int tda10021_i2c_gate_ctrl(struct dvb_frontend* fe, int enable)
{
	struct tda10021_state* state = fe->demodulator_priv;

	if (enable) {
		lock_tuner(state);
	} else {
		unlock_tuner(state);
	}
	return 0;
}