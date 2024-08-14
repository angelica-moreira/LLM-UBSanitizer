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
struct dvb_frontend {struct cx24113_state* tuner_priv; } ;
struct cx24113_state {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dprintk (char*) ; 
 int /*<<< orphan*/  kfree (struct cx24113_state*) ; 

__attribute__((used)) static void cx24113_release(struct dvb_frontend *fe)
{
	struct cx24113_state *state = fe->tuner_priv;
	dprintk("\n");
	fe->tuner_priv = NULL;
	kfree(state);
}