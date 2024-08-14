#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct TYPE_4__ {scalar_t__ no_tuner; } ;
struct zl10353_state {int bandwidth; TYPE_1__ config; int /*<<< orphan*/  frequency; } ;
struct TYPE_5__ {int /*<<< orphan*/  (* calc_regs ) (struct dvb_frontend*,int*,int) ;int /*<<< orphan*/  (* set_params ) (struct dvb_frontend*) ;} ;
struct TYPE_6__ {TYPE_2__ tuner_ops; int /*<<< orphan*/  (* i2c_gate_ctrl ) (struct dvb_frontend*,int /*<<< orphan*/ ) ;} ;
struct dtv_frontend_properties {int transmission_mode; int guard_interval; int bandwidth_hz; int code_rate_HP; int code_rate_LP; int hierarchy; int modulation; int /*<<< orphan*/  frequency; } ;
struct dvb_frontend {TYPE_3__ ops; struct zl10353_state* demodulator_priv; struct dtv_frontend_properties dtv_property_cache; } ;
typedef  int /*<<< orphan*/  pllbuf ;

/* Variables and functions */
 int ACQ_CTL ; 
 int AGC_TARGET ; 
 int EINVAL ; 
#define  FEC_1_2 151 
#define  FEC_2_3 150 
#define  FEC_3_4 149 
#define  FEC_5_6 148 
#define  FEC_7_8 147 
#define  FEC_AUTO 146 
#define  FEC_NONE 145 
 int FSM_GO ; 
#define  GUARD_INTERVAL_1_16 144 
#define  GUARD_INTERVAL_1_32 143 
#define  GUARD_INTERVAL_1_4 142 
#define  GUARD_INTERVAL_1_8 141 
#define  GUARD_INTERVAL_AUTO 140 
#define  HIERARCHY_1 139 
#define  HIERARCHY_2 138 
#define  HIERARCHY_4 137 
#define  HIERARCHY_AUTO 136 
#define  HIERARCHY_NONE 135 
 int INPUT_FREQ_0 ; 
 int INPUT_FREQ_1 ; 
 int MCLK_RATIO ; 
#define  QAM_16 134 
#define  QAM_64 133 
#define  QAM_AUTO 132 
#define  QPSK 131 
 int RESET ; 
 int TPS_GIVEN_0 ; 
 int TPS_GIVEN_1 ; 
#define  TRANSMISSION_MODE_2K 130 
#define  TRANSMISSION_MODE_8K 129 
#define  TRANSMISSION_MODE_AUTO 128 
 int TRL_NOMINAL_RATE_0 ; 
 int TRL_NOMINAL_RATE_1 ; 
 int TUNER_GO ; 
 int lsb (int) ; 
 int msb (int) ; 
 int /*<<< orphan*/  stub1 (struct dvb_frontend*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (struct dvb_frontend*) ; 
 int /*<<< orphan*/  stub3 (struct dvb_frontend*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (struct dvb_frontend*,int*,int) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  zl10353_calc_input_freq (struct dvb_frontend*,int*) ; 
 int /*<<< orphan*/  zl10353_calc_nominal_rate (struct dvb_frontend*,int,int*) ; 
 int /*<<< orphan*/  zl10353_single_write (struct dvb_frontend*,int,int) ; 
 int /*<<< orphan*/  zl10353_write (struct dvb_frontend*,int*,int) ; 

__attribute__((used)) static int zl10353_set_parameters(struct dvb_frontend *fe)
{
	struct dtv_frontend_properties *c = &fe->dtv_property_cache;
	struct zl10353_state *state = fe->demodulator_priv;
	u16 nominal_rate, input_freq;
	u8 pllbuf[6] = { 0x67 }, acq_ctl = 0;
	u16 tps = 0;

	state->frequency = c->frequency;

	zl10353_single_write(fe, RESET, 0x80);
	udelay(200);
	zl10353_single_write(fe, 0xEA, 0x01);
	udelay(200);
	zl10353_single_write(fe, 0xEA, 0x00);

	zl10353_single_write(fe, AGC_TARGET, 0x28);

	if (c->transmission_mode != TRANSMISSION_MODE_AUTO)
		acq_ctl |= (1 << 0);
	if (c->guard_interval != GUARD_INTERVAL_AUTO)
		acq_ctl |= (1 << 1);
	zl10353_single_write(fe, ACQ_CTL, acq_ctl);

	switch (c->bandwidth_hz) {
	case 6000000:
		/* These are extrapolated from the 7 and 8MHz values */
		zl10353_single_write(fe, MCLK_RATIO, 0x97);
		zl10353_single_write(fe, 0x64, 0x34);
		zl10353_single_write(fe, 0xcc, 0xdd);
		break;
	case 7000000:
		zl10353_single_write(fe, MCLK_RATIO, 0x86);
		zl10353_single_write(fe, 0x64, 0x35);
		zl10353_single_write(fe, 0xcc, 0x73);
		break;
	default:
		c->bandwidth_hz = 8000000;
		/* fall through */
	case 8000000:
		zl10353_single_write(fe, MCLK_RATIO, 0x75);
		zl10353_single_write(fe, 0x64, 0x36);
		zl10353_single_write(fe, 0xcc, 0x73);
	}

	zl10353_calc_nominal_rate(fe, c->bandwidth_hz, &nominal_rate);
	zl10353_single_write(fe, TRL_NOMINAL_RATE_1, msb(nominal_rate));
	zl10353_single_write(fe, TRL_NOMINAL_RATE_0, lsb(nominal_rate));
	state->bandwidth = c->bandwidth_hz;

	zl10353_calc_input_freq(fe, &input_freq);
	zl10353_single_write(fe, INPUT_FREQ_1, msb(input_freq));
	zl10353_single_write(fe, INPUT_FREQ_0, lsb(input_freq));

	/* Hint at TPS settings */
	switch (c->code_rate_HP) {
	case FEC_2_3:
		tps |= (1 << 7);
		break;
	case FEC_3_4:
		tps |= (2 << 7);
		break;
	case FEC_5_6:
		tps |= (3 << 7);
		break;
	case FEC_7_8:
		tps |= (4 << 7);
		break;
	case FEC_1_2:
	case FEC_AUTO:
		break;
	default:
		return -EINVAL;
	}

	switch (c->code_rate_LP) {
	case FEC_2_3:
		tps |= (1 << 4);
		break;
	case FEC_3_4:
		tps |= (2 << 4);
		break;
	case FEC_5_6:
		tps |= (3 << 4);
		break;
	case FEC_7_8:
		tps |= (4 << 4);
		break;
	case FEC_1_2:
	case FEC_AUTO:
		break;
	case FEC_NONE:
		if (c->hierarchy == HIERARCHY_AUTO ||
		    c->hierarchy == HIERARCHY_NONE)
			break;
		/* fall through */
	default:
		return -EINVAL;
	}

	switch (c->modulation) {
	case QPSK:
		break;
	case QAM_AUTO:
	case QAM_16:
		tps |= (1 << 13);
		break;
	case QAM_64:
		tps |= (2 << 13);
		break;
	default:
		return -EINVAL;
	}

	switch (c->transmission_mode) {
	case TRANSMISSION_MODE_2K:
	case TRANSMISSION_MODE_AUTO:
		break;
	case TRANSMISSION_MODE_8K:
		tps |= (1 << 0);
		break;
	default:
		return -EINVAL;
	}

	switch (c->guard_interval) {
	case GUARD_INTERVAL_1_32:
	case GUARD_INTERVAL_AUTO:
		break;
	case GUARD_INTERVAL_1_16:
		tps |= (1 << 2);
		break;
	case GUARD_INTERVAL_1_8:
		tps |= (2 << 2);
		break;
	case GUARD_INTERVAL_1_4:
		tps |= (3 << 2);
		break;
	default:
		return -EINVAL;
	}

	switch (c->hierarchy) {
	case HIERARCHY_AUTO:
	case HIERARCHY_NONE:
		break;
	case HIERARCHY_1:
		tps |= (1 << 10);
		break;
	case HIERARCHY_2:
		tps |= (2 << 10);
		break;
	case HIERARCHY_4:
		tps |= (3 << 10);
		break;
	default:
		return -EINVAL;
	}

	zl10353_single_write(fe, TPS_GIVEN_1, msb(tps));
	zl10353_single_write(fe, TPS_GIVEN_0, lsb(tps));

	if (fe->ops.i2c_gate_ctrl)
		fe->ops.i2c_gate_ctrl(fe, 0);

	/*
	 * If there is no tuner attached to the secondary I2C bus, we call
	 * set_params to program a potential tuner attached somewhere else.
	 * Otherwise, we update the PLL registers via calc_regs.
	 */
	if (state->config.no_tuner) {
		if (fe->ops.tuner_ops.set_params) {
			fe->ops.tuner_ops.set_params(fe);
			if (fe->ops.i2c_gate_ctrl)
				fe->ops.i2c_gate_ctrl(fe, 0);
		}
	} else if (fe->ops.tuner_ops.calc_regs) {
		fe->ops.tuner_ops.calc_regs(fe, pllbuf + 1, 5);
		pllbuf[1] <<= 1;
		zl10353_write(fe, pllbuf, sizeof(pllbuf));
	}

	zl10353_single_write(fe, 0x5F, 0x13);

	/* If no attached tuner or invalid PLL registers, just start the FSM. */
	if (state->config.no_tuner || fe->ops.tuner_ops.calc_regs == NULL)
		zl10353_single_write(fe, FSM_GO, 0x01);
	else
		zl10353_single_write(fe, TUNER_GO, 0x01);

	return 0;
}