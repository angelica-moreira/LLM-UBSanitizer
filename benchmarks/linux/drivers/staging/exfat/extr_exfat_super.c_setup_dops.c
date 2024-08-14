#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct super_block {int /*<<< orphan*/ * s_d_op; } ;
struct TYPE_3__ {scalar_t__ casesensitive; } ;
struct TYPE_4__ {TYPE_1__ options; } ;

/* Variables and functions */
 TYPE_2__* EXFAT_SB (struct super_block*) ; 
 int /*<<< orphan*/  exfat_ci_dentry_ops ; 
 int /*<<< orphan*/  exfat_dentry_ops ; 

__attribute__((used)) static void setup_dops(struct super_block *sb)
{
	if (EXFAT_SB(sb)->options.casesensitive == 0)
		sb->s_d_op = &exfat_ci_dentry_ops;
	else
		sb->s_d_op = &exfat_dentry_ops;
}