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
struct inode {int dummy; } ;
struct TYPE_2__ {unsigned long ncleansegs; } ;

/* Variables and functions */
 TYPE_1__* NILFS_SUI (struct inode*) ; 

unsigned long nilfs_sufile_get_ncleansegs(struct inode *sufile)
{
	return NILFS_SUI(sufile)->ncleansegs;
}