#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct inode {int /*<<< orphan*/  i_sb; } ;
struct TYPE_2__ {scalar_t__ log; } ;

/* Variables and functions */
 TYPE_1__* JFS_SBI (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int isReadOnly(struct inode *inode)
{
	if (JFS_SBI(inode->i_sb)->log)
		return 0;
	return 1;
}