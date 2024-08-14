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
struct s5h1420_state {int /*<<< orphan*/  tuner_i2c_adapter; } ;
struct dvb_frontend {struct s5h1420_state* demodulator_priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  i2c_del_adapter (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct s5h1420_state*) ; 

__attribute__((used)) static void s5h1420_release(struct dvb_frontend* fe)
{
	struct s5h1420_state* state = fe->demodulator_priv;
	i2c_del_adapter(&state->tuner_i2c_adapter);
	kfree(state);
}