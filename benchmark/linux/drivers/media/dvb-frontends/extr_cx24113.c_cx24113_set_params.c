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
typedef  int u32 ;
struct dtv_frontend_properties {int symbol_rate; int /*<<< orphan*/  frequency; } ;
struct dvb_frontend {struct cx24113_state* tuner_priv; struct dtv_frontend_properties dtv_property_cache; } ;
struct cx24113_state {int dummy; } ;

/* Variables and functions */
 int cx24113_get_status (struct dvb_frontend*,int*) ; 
 int /*<<< orphan*/  cx24113_set_bandwidth (struct cx24113_state*,int) ; 
 int /*<<< orphan*/  cx24113_set_frequency (struct cx24113_state*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 

__attribute__((used)) static int cx24113_set_params(struct dvb_frontend *fe)
{
	struct dtv_frontend_properties *c = &fe->dtv_property_cache;
	struct cx24113_state *state = fe->tuner_priv;
	/* for a ROLL-OFF factor of 0.35, 0.2: 600, 0.25: 625 */
	u32 roll_off = 675;
	u32 bw;

	bw  = ((c->symbol_rate/100) * roll_off) / 1000;
	bw += (10000000/100) + 5;
	bw /= 10;
	bw += 1000;
	cx24113_set_bandwidth(state, bw);

	cx24113_set_frequency(state, c->frequency);
	msleep(5);
	return cx24113_get_status(fe, &bw);
}