#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {int /*<<< orphan*/  f_out; } ;
struct mt2063_state {TYPE_1__ AS_Data; int /*<<< orphan*/  init; } ;
struct dvb_frontend {struct mt2063_state* tuner_priv; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  dprintk (int,char*,...) ; 

__attribute__((used)) static int mt2063_get_if_frequency(struct dvb_frontend *fe, u32 *freq)
{
	struct mt2063_state *state = fe->tuner_priv;

	dprintk(2, "\n");

	if (!state->init)
		return -ENODEV;

	*freq = state->AS_Data.f_out;

	dprintk(1, "IF frequency: %d\n", *freq);

	return 0;
}