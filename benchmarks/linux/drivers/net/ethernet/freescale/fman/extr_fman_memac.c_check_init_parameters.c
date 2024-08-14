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
struct fman_mac {scalar_t__ addr; int /*<<< orphan*/  event_cb; int /*<<< orphan*/  exception_cb; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 

__attribute__((used)) static int check_init_parameters(struct fman_mac *memac)
{
	if (memac->addr == 0) {
		pr_err("Ethernet MAC must have a valid MAC address\n");
		return -EINVAL;
	}
	if (!memac->exception_cb) {
		pr_err("Uninitialized exception handler\n");
		return -EINVAL;
	}
	if (!memac->event_cb) {
		pr_warn("Uninitialize event handler\n");
		return -EINVAL;
	}

	return 0;
}