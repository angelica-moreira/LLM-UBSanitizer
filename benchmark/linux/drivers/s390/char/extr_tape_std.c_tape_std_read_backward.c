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
struct tape_request {scalar_t__ cpaddr; int /*<<< orphan*/  op; } ;
struct TYPE_2__ {int /*<<< orphan*/  idal_buf; } ;
struct tape_device {TYPE_1__ char_data; int /*<<< orphan*/ * modeset_byte; } ;

/* Variables and functions */
 int /*<<< orphan*/  DBF_EVENT (int,char*) ; 
 int /*<<< orphan*/  FORSPACEBLOCK ; 
 int /*<<< orphan*/  MODE_SET_DB ; 
 int /*<<< orphan*/  NOP ; 
 int /*<<< orphan*/  READ_BACKWARD ; 
 int /*<<< orphan*/  TO_RBA ; 
 int /*<<< orphan*/  tape_ccw_cc (scalar_t__,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tape_ccw_cc_idal (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tape_ccw_end (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void
tape_std_read_backward(struct tape_device *device, struct tape_request *request)
{
	/*
	 * We have allocated 4 ccws in tape_std_read, so we can now
	 * transform the request to a read backward, followed by a
	 * forward space block.
	 */
	request->op = TO_RBA;
	tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1, device->modeset_byte);
	tape_ccw_cc_idal(request->cpaddr + 1, READ_BACKWARD,
			 device->char_data.idal_buf);
	tape_ccw_cc(request->cpaddr + 2, FORSPACEBLOCK, 0, NULL);
	tape_ccw_end(request->cpaddr + 3, NOP, 0, NULL);
	DBF_EVENT(6, "xrop ccwg");}