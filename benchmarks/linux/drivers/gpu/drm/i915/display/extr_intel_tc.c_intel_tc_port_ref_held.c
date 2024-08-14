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
struct intel_digital_port {scalar_t__ tc_link_refcount; int /*<<< orphan*/  tc_lock; } ;

/* Variables and functions */
 scalar_t__ mutex_is_locked (int /*<<< orphan*/ *) ; 

bool intel_tc_port_ref_held(struct intel_digital_port *dig_port)
{
	return mutex_is_locked(&dig_port->tc_lock) ||
	       dig_port->tc_link_refcount;
}