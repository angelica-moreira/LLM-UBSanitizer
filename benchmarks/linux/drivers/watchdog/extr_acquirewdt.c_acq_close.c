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
struct inode {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  acq_is_open ; 
 int /*<<< orphan*/  acq_keepalive () ; 
 int /*<<< orphan*/  acq_stop () ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int expect_close ; 
 int /*<<< orphan*/  pr_crit (char*) ; 

__attribute__((used)) static int acq_close(struct inode *inode, struct file *file)
{
	if (expect_close == 42) {
		acq_stop();
	} else {
		pr_crit("Unexpected close, not stopping watchdog!\n");
		acq_keepalive();
	}
	clear_bit(0, &acq_is_open);
	expect_close = 0;
	return 0;
}