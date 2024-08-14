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
typedef  int /*<<< orphan*/  u32 ;
struct ath6kl {TYPE_1__* hif_ops; } ;
typedef  int /*<<< orphan*/  __le32 ;
struct TYPE_2__ {int (* diag_write32 ) (struct ath6kl*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int stub1 (struct ath6kl*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int ath6kl_hif_diag_write32(struct ath6kl *ar, u32 address,
					  __le32 value)
{
	return ar->hif_ops->diag_write32(ar, address, value);
}