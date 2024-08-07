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
struct dtv_frontend_properties {int /*<<< orphan*/  frequency; int /*<<< orphan*/  rolloff; int /*<<< orphan*/  symbol_rate; } ;
struct dvb_frontend {struct dtv_frontend_properties dtv_property_cache; } ;

/* Variables and functions */
 int /*<<< orphan*/  carrier_width (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stv6110_set_bandwidth (struct dvb_frontend*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stv6110_set_frequency (struct dvb_frontend*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int stv6110_set_params(struct dvb_frontend *fe)
{
	struct dtv_frontend_properties *c = &fe->dtv_property_cache;
	u32 bandwidth = carrier_width(c->symbol_rate, c->rolloff);

	stv6110_set_frequency(fe, c->frequency);
	stv6110_set_bandwidth(fe, bandwidth);

	return 0;
}