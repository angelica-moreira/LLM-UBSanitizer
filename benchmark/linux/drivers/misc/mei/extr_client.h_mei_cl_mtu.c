#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct mei_cl {TYPE_2__* me_cl; } ;
struct TYPE_3__ {size_t max_msg_length; } ;
struct TYPE_4__ {TYPE_1__ props; } ;

/* Variables and functions */

__attribute__((used)) static inline size_t mei_cl_mtu(const struct mei_cl *cl)
{
	return cl->me_cl->props.max_msg_length;
}