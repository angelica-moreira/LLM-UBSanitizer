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
struct ufs_hba {TYPE_1__* vops; } ;
struct TYPE_2__ {int (* hce_enable_notify ) (struct ufs_hba*,int) ;} ;

/* Variables and functions */
 int stub1 (struct ufs_hba*,int) ; 

__attribute__((used)) static inline int ufshcd_vops_hce_enable_notify(struct ufs_hba *hba,
						bool status)
{
	if (hba->vops && hba->vops->hce_enable_notify)
		return hba->vops->hce_enable_notify(hba, status);

	return 0;
}