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
struct TYPE_2__ {scalar_t__ next; } ;
struct msg_sender {TYPE_1__ list; } ;

/* Variables and functions */
 int /*<<< orphan*/  list_del (TYPE_1__*) ; 

__attribute__((used)) static inline void ss_del(struct msg_sender *mss)
{
	if (mss->list.next)
		list_del(&mss->list);
}