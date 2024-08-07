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
struct or51211_state {TYPE_1__* config; } ;
struct dvb_frontend {struct or51211_state* demodulator_priv; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* sleep ) (struct dvb_frontend*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct or51211_state*) ; 
 int /*<<< orphan*/  stub1 (struct dvb_frontend*) ; 

__attribute__((used)) static void or51211_release(struct dvb_frontend* fe)
{
	struct or51211_state* state = fe->demodulator_priv;
	state->config->sleep(fe);
	kfree(state);
}