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
struct TYPE_2__ {scalar_t__ expires; } ;
struct yenta_socket {TYPE_1__ poll_timer; } ;
struct timer_list {int dummy; } ;

/* Variables and functions */
 scalar_t__ HZ ; 
 int /*<<< orphan*/  add_timer (TYPE_1__*) ; 
 struct yenta_socket* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  poll_timer ; 
 struct yenta_socket* socket ; 
 int /*<<< orphan*/  yenta_interrupt (int /*<<< orphan*/ ,void*) ; 

__attribute__((used)) static void yenta_interrupt_wrapper(struct timer_list *t)
{
	struct yenta_socket *socket = from_timer(socket, t, poll_timer);

	yenta_interrupt(0, (void *)socket);
	socket->poll_timer.expires = jiffies + HZ;
	add_timer(&socket->poll_timer);
}