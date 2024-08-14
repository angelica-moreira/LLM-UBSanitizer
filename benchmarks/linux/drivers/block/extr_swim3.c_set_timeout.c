#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {void (* function ) (struct timer_list*) ;scalar_t__ expires; } ;
struct floppy_state {int timeout_pending; TYPE_1__ timeout; } ;

/* Variables and functions */
 int /*<<< orphan*/  add_timer (TYPE_1__*) ; 
 int /*<<< orphan*/  del_timer (TYPE_1__*) ; 
 scalar_t__ jiffies ; 

__attribute__((used)) static void set_timeout(struct floppy_state *fs, int nticks,
			void (*proc)(struct timer_list *t))
{
	if (fs->timeout_pending)
		del_timer(&fs->timeout);
	fs->timeout.expires = jiffies + nticks;
	fs->timeout.function = proc;
	add_timer(&fs->timeout);
	fs->timeout_pending = 1;
}