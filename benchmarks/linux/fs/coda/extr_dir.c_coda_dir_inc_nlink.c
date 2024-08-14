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
struct inode {int i_nlink; } ;

/* Variables and functions */
 int /*<<< orphan*/  inc_nlink (struct inode*) ; 

__attribute__((used)) static inline void coda_dir_inc_nlink(struct inode *dir)
{
	if (dir->i_nlink >= 2)
		inc_nlink(dir);
}