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
struct cc_hw_desc {int dummy; } ;
struct cc_drvdata {scalar_t__ hw_rev; } ;

/* Variables and functions */
 scalar_t__ CC_HW_REV_712 ; 
 int /*<<< orphan*/  set_queue_last_ind_bit (struct cc_hw_desc*) ; 

__attribute__((used)) static inline void set_queue_last_ind(struct cc_drvdata *drvdata,
				      struct cc_hw_desc *pdesc)
{
	if (drvdata->hw_rev >= CC_HW_REV_712)
		set_queue_last_ind_bit(pdesc);
}