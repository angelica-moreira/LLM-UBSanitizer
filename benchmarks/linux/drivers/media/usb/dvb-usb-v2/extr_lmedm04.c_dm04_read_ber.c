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
typedef  scalar_t__ u32 ;
struct lme2510_state {int (* fe_read_ber ) (struct dvb_frontend*,scalar_t__*) ;int /*<<< orphan*/  stream_on; } ;
struct dvb_frontend {int dummy; } ;

/* Variables and functions */
 struct lme2510_state* fe_to_priv (struct dvb_frontend*) ; 
 int stub1 (struct dvb_frontend*,scalar_t__*) ; 

__attribute__((used)) static int dm04_read_ber(struct dvb_frontend *fe, u32 *ber)
{
	struct lme2510_state *st = fe_to_priv(fe);

	if (st->fe_read_ber && !st->stream_on)
		return st->fe_read_ber(fe, ber);

	*ber = 0;

	return 0;
}