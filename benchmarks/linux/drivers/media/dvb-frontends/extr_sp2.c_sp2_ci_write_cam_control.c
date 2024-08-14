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
typedef  int /*<<< orphan*/  u8 ;
struct dvb_ca_en50221 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SP2_CI_IO_ACS ; 
 int /*<<< orphan*/  SP2_CI_WR ; 
 int sp2_ci_op_cam (struct dvb_ca_en50221*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int sp2_ci_write_cam_control(struct dvb_ca_en50221 *en50221,
				int slot, u8 addr, u8 data)
{
	return sp2_ci_op_cam(en50221, slot, SP2_CI_IO_ACS,
			SP2_CI_WR, addr, data);
}