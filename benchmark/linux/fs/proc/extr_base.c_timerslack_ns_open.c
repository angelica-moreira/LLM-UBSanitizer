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
 int single_open (struct file*,int /*<<< orphan*/ ,struct inode*) ; 
 int /*<<< orphan*/  timerslack_ns_show ; 

__attribute__((used)) static int timerslack_ns_open(struct inode *inode, struct file *filp)
{
	return single_open(filp, timerslack_ns_show, inode);
}