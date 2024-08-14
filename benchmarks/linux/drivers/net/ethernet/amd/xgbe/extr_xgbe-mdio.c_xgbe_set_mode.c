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
struct xgbe_prv_data {int dummy; } ;
typedef  enum xgbe_mode { ____Placeholder_xgbe_mode } xgbe_mode ;

/* Variables and functions */
 int /*<<< orphan*/  xgbe_change_mode (struct xgbe_prv_data*,int) ; 
 int xgbe_cur_mode (struct xgbe_prv_data*) ; 

__attribute__((used)) static bool xgbe_set_mode(struct xgbe_prv_data *pdata,
			  enum xgbe_mode mode)
{
	if (mode == xgbe_cur_mode(pdata))
		return false;

	xgbe_change_mode(pdata, mode);

	return true;
}