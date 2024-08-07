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
struct dvb_frontend {struct sp8870_state* demodulator_priv; int /*<<< orphan*/  ops; } ;
struct sp8870_state {struct dvb_frontend frontend; scalar_t__ initialised; struct i2c_adapter* i2c; struct sp8870_config const* config; } ;
struct sp8870_config {int dummy; } ;
struct i2c_adapter {int dummy; } ;
struct dvb_frontend_ops {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  kfree (struct sp8870_state*) ; 
 struct sp8870_state* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sp8870_ops ; 
 scalar_t__ sp8870_readreg (struct sp8870_state*,int) ; 

struct dvb_frontend* sp8870_attach(const struct sp8870_config* config,
				   struct i2c_adapter* i2c)
{
	struct sp8870_state* state = NULL;

	/* allocate memory for the internal state */
	state = kzalloc(sizeof(struct sp8870_state), GFP_KERNEL);
	if (state == NULL) goto error;

	/* setup the state */
	state->config = config;
	state->i2c = i2c;
	state->initialised = 0;

	/* check if the demod is there */
	if (sp8870_readreg(state, 0x0200) < 0) goto error;

	/* create dvb_frontend */
	memcpy(&state->frontend.ops, &sp8870_ops, sizeof(struct dvb_frontend_ops));
	state->frontend.demodulator_priv = state;
	return &state->frontend;

error:
	kfree(state);
	return NULL;
}