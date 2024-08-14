#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
struct dvb_frontend {struct dib8000_state* demodulator_priv; } ;
struct dib8000_state {int revision; TYPE_2__** fe; } ;
struct TYPE_3__ {int (* sleep ) (TYPE_2__*) ;} ;
struct TYPE_4__ {TYPE_1__ ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  DIB8000_POWER_INTERFACE_ONLY ; 
 int /*<<< orphan*/  DIBX000_ADC_OFF ; 
 int /*<<< orphan*/  DIBX000_SLOW_ADC_OFF ; 
 size_t MAX_NUMBER_OF_FRONTENDS ; 
 int /*<<< orphan*/  OUTMODE_HIGH_Z ; 
 int dib8000_set_adc_state (struct dib8000_state*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dib8000_set_output_mode (struct dvb_frontend*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dib8000_set_power_mode (struct dib8000_state*,int /*<<< orphan*/ ) ; 
 int stub1 (TYPE_2__*) ; 

__attribute__((used)) static int dib8000_sleep(struct dvb_frontend *fe)
{
	struct dib8000_state *state = fe->demodulator_priv;
	u8 index_frontend;
	int ret;

	for (index_frontend = 1; (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL); index_frontend++) {
		ret = state->fe[index_frontend]->ops.sleep(state->fe[index_frontend]);
		if (ret < 0)
			return ret;
	}

	if (state->revision != 0x8090)
		dib8000_set_output_mode(fe, OUTMODE_HIGH_Z);
	dib8000_set_power_mode(state, DIB8000_POWER_INTERFACE_ONLY);
	return dib8000_set_adc_state(state, DIBX000_SLOW_ADC_OFF) | dib8000_set_adc_state(state, DIBX000_ADC_OFF);
}