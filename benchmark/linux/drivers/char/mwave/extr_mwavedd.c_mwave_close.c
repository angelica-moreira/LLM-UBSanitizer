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
 int /*<<< orphan*/  PRINTK_2 (int /*<<< orphan*/ ,char*,unsigned int) ; 
 int /*<<< orphan*/  PRINTK_3 (int /*<<< orphan*/ ,char*,struct inode*,struct file*) ; 
 int /*<<< orphan*/  TRACE_MWAVE ; 

__attribute__((used)) static int mwave_close(struct inode *inode, struct file *file)
{
	unsigned int retval = 0;

	PRINTK_3(TRACE_MWAVE,
		"mwavedd::mwave_close, entry inode %p file %p\n",
		 inode,  file);

	PRINTK_2(TRACE_MWAVE, "mwavedd::mwave_close, exit retval %x\n",
		retval);

	return retval;
}