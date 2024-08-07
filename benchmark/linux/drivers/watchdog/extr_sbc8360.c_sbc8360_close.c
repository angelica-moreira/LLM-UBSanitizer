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
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int expect_close ; 
 int /*<<< orphan*/  pr_crit (char*) ; 
 int /*<<< orphan*/  sbc8360_is_open ; 
 int /*<<< orphan*/  sbc8360_stop () ; 

__attribute__((used)) static int sbc8360_close(struct inode *inode, struct file *file)
{
	if (expect_close == 42)
		sbc8360_stop();
	else
		pr_crit("SBC8360 device closed unexpectedly.  SBC8360 will not stop!\n");

	clear_bit(0, &sbc8360_is_open);
	expect_close = 0;
	return 0;
}