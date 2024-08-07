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
typedef  int u16 ;
struct sp887x_state {int dummy; } ;
struct dvb_frontend {struct sp887x_state* demodulator_priv; } ;

/* Variables and functions */
 int sp887x_readreg (struct sp887x_state*,int) ; 

__attribute__((used)) static int sp887x_read_signal_strength(struct dvb_frontend* fe, u16* strength)
{
	struct sp887x_state* state = fe->demodulator_priv;

	u16 snr12 = sp887x_readreg(state, 0xf16);
	u32 signal = 3 * (snr12 << 4);
	*strength = (signal < 0xffff) ? signal : 0xffff;

	return 0;
}