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
struct TYPE_2__ {int /*<<< orphan*/  (* interrupt ) () ;} ;

/* Variables and functions */
 int /*<<< orphan*/  cancel_delayed_work (int /*<<< orphan*/ *) ; 
 TYPE_1__* cont ; 
 int /*<<< orphan*/  fd_timer ; 
 int /*<<< orphan*/  stub1 () ; 

__attribute__((used)) static void main_command_interrupt(void)
{
	cancel_delayed_work(&fd_timer);
	cont->interrupt();
}