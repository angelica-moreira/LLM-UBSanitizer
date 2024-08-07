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
 int /*<<< orphan*/  SOCKET_I (struct inode*) ; 
 int /*<<< orphan*/  __sock_release (int /*<<< orphan*/ ,struct inode*) ; 

__attribute__((used)) static int sock_close(struct inode *inode, struct file *filp)
{
	__sock_release(SOCKET_I(inode), inode);
	return 0;
}