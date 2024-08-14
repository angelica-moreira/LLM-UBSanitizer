#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  release; } ;
struct TYPE_4__ {int /*<<< orphan*/  release; } ;
struct TYPE_6__ {TYPE_2__ analog_ops; TYPE_1__ tuner_ops; int /*<<< orphan*/  release_sec; } ;
struct dvb_frontend {TYPE_3__ ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  dvb_frontend_invoke_release (struct dvb_frontend*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dvb_frontend_put (struct dvb_frontend*) ; 

void dvb_frontend_detach(struct dvb_frontend *fe)
{
	dvb_frontend_invoke_release(fe, fe->ops.release_sec);
	dvb_frontend_invoke_release(fe, fe->ops.tuner_ops.release);
	dvb_frontend_invoke_release(fe, fe->ops.analog_ops.release);
	dvb_frontend_put(fe);
}