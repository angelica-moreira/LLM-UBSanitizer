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
struct file {int dummy; } ;
struct autofs_sb_info {int dummy; } ;
struct TYPE_2__ {scalar_t__ token; } ;
struct autofs_dev_ioctl {TYPE_1__ ready; } ;
typedef  scalar_t__ autofs_wqt_t ;

/* Variables and functions */
 int autofs_wait_release (struct autofs_sb_info*,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int autofs_dev_ioctl_ready(struct file *fp,
				  struct autofs_sb_info *sbi,
				  struct autofs_dev_ioctl *param)
{
	autofs_wqt_t token;

	token = (autofs_wqt_t) param->ready.token;
	return autofs_wait_release(sbi, token, 0);
}