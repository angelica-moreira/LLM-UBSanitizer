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
struct dvb_usb_adapter {TYPE_1__* fe_adap; } ;
struct TYPE_2__ {int /*<<< orphan*/  fe; } ;

/* Variables and functions */
 int dib9000_fw_pid_filter_ctrl (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int dib90x0_pid_filter_ctrl(struct dvb_usb_adapter *adapter, int onoff)
{
	return dib9000_fw_pid_filter_ctrl(adapter->fe_adap[0].fe, onoff);
}