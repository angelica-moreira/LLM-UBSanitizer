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
struct dvb_frontend {struct dib7000p_state* demodulator_priv; } ;
struct dib7000p_state {int /*<<< orphan*/  dib7090_tuner_adap; int /*<<< orphan*/  i2c_master; } ;

/* Variables and functions */
 int /*<<< orphan*/  dibx000_exit_i2c_master (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2c_del_adapter (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct dib7000p_state*) ; 

__attribute__((used)) static void dib7000p_release(struct dvb_frontend *demod)
{
	struct dib7000p_state *st = demod->demodulator_priv;
	dibx000_exit_i2c_master(&st->i2c_master);
	i2c_del_adapter(&st->dib7090_tuner_adap);
	kfree(st);
}