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
typedef  int /*<<< orphan*/  u32 ;
struct ix2505v_state {int /*<<< orphan*/  frequency; } ;
struct dvb_frontend {struct ix2505v_state* tuner_priv; } ;

/* Variables and functions */

__attribute__((used)) static int ix2505v_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
	struct ix2505v_state *state = fe->tuner_priv;

	*frequency = state->frequency;

	return 0;
}