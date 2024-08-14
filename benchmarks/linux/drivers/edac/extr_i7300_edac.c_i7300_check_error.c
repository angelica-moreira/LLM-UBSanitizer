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
struct mem_ctl_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  i7300_process_error_global (struct mem_ctl_info*) ; 
 int /*<<< orphan*/  i7300_process_fbd_error (struct mem_ctl_info*) ; 

__attribute__((used)) static void i7300_check_error(struct mem_ctl_info *mci)
{
	i7300_process_error_global(mci);
	i7300_process_fbd_error(mci);
}