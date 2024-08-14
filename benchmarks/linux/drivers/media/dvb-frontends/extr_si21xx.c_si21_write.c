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
typedef  int /*<<< orphan*/  u8 ;
struct si21xx_state {int dummy; } ;
struct dvb_frontend {struct si21xx_state* demodulator_priv; } ;

/* Variables and functions */
 int EINVAL ; 
 int si21_writereg (struct si21xx_state*,int /*<<< orphan*/  const,int /*<<< orphan*/  const) ; 

__attribute__((used)) static int si21_write(struct dvb_frontend *fe, const u8 buf[], int len)
{
	struct si21xx_state *state = fe->demodulator_priv;

	if (len != 2)
		return -EINVAL;

	return si21_writereg(state, buf[0], buf[1]);
}