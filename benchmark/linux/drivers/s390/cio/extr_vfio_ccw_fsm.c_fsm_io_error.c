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
struct vfio_ccw_private {TYPE_1__* io_region; int /*<<< orphan*/  state; } ;
typedef  enum vfio_ccw_event { ____Placeholder_vfio_ccw_event } vfio_ccw_event ;
struct TYPE_2__ {int /*<<< orphan*/  ret_code; } ;

/* Variables and functions */
 int /*<<< orphan*/  EIO ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void fsm_io_error(struct vfio_ccw_private *private,
			 enum vfio_ccw_event event)
{
	pr_err("vfio-ccw: FSM: I/O request from state:%d\n", private->state);
	private->io_region->ret_code = -EIO;
}