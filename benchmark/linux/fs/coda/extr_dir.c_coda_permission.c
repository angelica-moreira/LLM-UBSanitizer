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
struct inode {int /*<<< orphan*/  i_sb; } ;

/* Variables and functions */
 int EACCES ; 
 int ECHILD ; 
 int MAY_EXEC ; 
 int MAY_NOT_BLOCK ; 
 int MAY_READ ; 
 int MAY_WRITE ; 
 scalar_t__ coda_cache_check (struct inode*,int) ; 
 int /*<<< orphan*/  coda_cache_enter (struct inode*,int) ; 
 int /*<<< orphan*/  coda_i2f (struct inode*) ; 
 int /*<<< orphan*/  execute_ok (struct inode*) ; 
 int venus_access (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

int coda_permission(struct inode *inode, int mask)
{
	int error;

	if (mask & MAY_NOT_BLOCK)
		return -ECHILD;

	mask &= MAY_READ | MAY_WRITE | MAY_EXEC;
 
	if (!mask)
		return 0;

	if ((mask & MAY_EXEC) && !execute_ok(inode))
		return -EACCES;

	if (coda_cache_check(inode, mask))
		return 0;

	error = venus_access(inode->i_sb, coda_i2f(inode), mask);
    
	if (!error)
		coda_cache_enter(inode, mask);

	return error;
}