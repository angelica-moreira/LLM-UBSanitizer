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
struct ttusb {int voltage; } ;
struct dvb_frontend {TYPE_1__* dvb; } ;
typedef  enum fe_sec_voltage { ____Placeholder_fe_sec_voltage } fe_sec_voltage ;
struct TYPE_2__ {scalar_t__ priv; } ;

/* Variables and functions */
 int ttusb_update_lnb (struct ttusb*) ; 

__attribute__((used)) static int ttusb_set_voltage(struct dvb_frontend *fe,
			     enum fe_sec_voltage voltage)
{
	struct ttusb* ttusb = (struct ttusb*) fe->dvb->priv;

	ttusb->voltage = voltage;
	return ttusb_update_lnb(ttusb);
}