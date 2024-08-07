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
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_4__ {TYPE_1__* ops; } ;
struct ath10k {TYPE_2__ hif; } ;
struct TYPE_3__ {int (* set_target_log_mode ) (struct ath10k*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int stub1 (struct ath10k*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int ath10k_hif_set_target_log_mode(struct ath10k *ar,
						 u8 fw_log_mode)
{
	if (!ar->hif.ops->set_target_log_mode)
		return -EOPNOTSUPP;

	return ar->hif.ops->set_target_log_mode(ar, fw_log_mode);
}