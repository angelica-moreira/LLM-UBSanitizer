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
struct machine {scalar_t__ pid; } ;

/* Variables and functions */
 scalar_t__ DEFAULT_GUEST_KERNEL_ID ; 

__attribute__((used)) static inline bool machine__is_default_guest(struct machine *machine)
{
	return machine ? machine->pid == DEFAULT_GUEST_KERNEL_ID : false;
}