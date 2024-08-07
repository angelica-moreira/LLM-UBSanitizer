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

/* Variables and functions */
 scalar_t__ XGBE_MODE_KR ; 
 scalar_t__ xgbe_cur_mode (struct xgbe_prv_data*) ; 

__attribute__((used)) static bool xgbe_in_kr_mode(struct xgbe_prv_data *pdata)
{
	return (xgbe_cur_mode(pdata) == XGBE_MODE_KR);
}