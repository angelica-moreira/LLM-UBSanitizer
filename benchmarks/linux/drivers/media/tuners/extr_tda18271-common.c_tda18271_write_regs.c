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
struct dvb_frontend {int dummy; } ;

/* Variables and functions */
 int __tda18271_write_regs (struct dvb_frontend*,int,int,int) ; 

int tda18271_write_regs(struct dvb_frontend *fe, int idx, int len)
{
	return __tda18271_write_regs(fe, idx, len, true);
}