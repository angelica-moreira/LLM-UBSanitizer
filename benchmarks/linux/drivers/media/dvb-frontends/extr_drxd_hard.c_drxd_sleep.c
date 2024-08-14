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
struct dvb_frontend {struct drxd_state* demodulator_priv; } ;
struct drxd_state {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ConfigureMPEGOutput (struct drxd_state*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int drxd_sleep(struct dvb_frontend *fe)
{
	struct drxd_state *state = fe->demodulator_priv;

	ConfigureMPEGOutput(state, 0);
	return 0;
}