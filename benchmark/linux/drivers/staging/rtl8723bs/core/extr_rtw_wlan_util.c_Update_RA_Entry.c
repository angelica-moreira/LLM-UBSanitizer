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
struct sta_info {int dummy; } ;
struct adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  rtw_hal_update_ra_mask (struct sta_info*,int /*<<< orphan*/ ) ; 

void Update_RA_Entry(struct adapter *padapter, struct sta_info *psta)
{
	rtw_hal_update_ra_mask(psta, 0);
}