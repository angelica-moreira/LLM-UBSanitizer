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
struct dvb_frontend {int dummy; } ;

/* Variables and functions */
 int au8522_read_ucblocks (struct dvb_frontend*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int au8522_read_ber(struct dvb_frontend *fe, u32 *ber)
{
	return au8522_read_ucblocks(fe, ber);
}