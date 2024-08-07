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
struct TYPE_2__ {int value; scalar_t__ offline; } ;

/* Variables and functions */
 TYPE_1__* xpc_heartbeat_uv ; 

__attribute__((used)) static void
xpc_heartbeat_init_uv(void)
{
	xpc_heartbeat_uv->value = 1;
	xpc_heartbeat_uv->offline = 0;
}