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
struct tape_request {int /*<<< orphan*/ * callback_data; void* callback; int /*<<< orphan*/  cpdata; int /*<<< orphan*/  cpaddr; int /*<<< orphan*/  op; } ;
struct tape_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DBF_EXCEPTION (int,char*) ; 
 scalar_t__ IS_ERR (struct tape_request*) ; 
 int /*<<< orphan*/  SENSE ; 
 int /*<<< orphan*/  TO_MSEN ; 
 scalar_t__ __tape_34xx_medium_sense ; 
 struct tape_request* tape_alloc_request (int,int) ; 
 int /*<<< orphan*/  tape_ccw_end (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tape_do_io_async (struct tape_device*,struct tape_request*) ; 

__attribute__((used)) static void tape_34xx_medium_sense_async(struct tape_device *device)
{
	struct tape_request *request;

	request = tape_alloc_request(1, 32);
	if (IS_ERR(request)) {
		DBF_EXCEPTION(6, "MSEN fail\n");
		return;
	}

	request->op = TO_MSEN;
	tape_ccw_end(request->cpaddr, SENSE, 32, request->cpdata);
	request->callback = (void *) __tape_34xx_medium_sense;
	request->callback_data = NULL;
	tape_do_io_async(device, request);
}