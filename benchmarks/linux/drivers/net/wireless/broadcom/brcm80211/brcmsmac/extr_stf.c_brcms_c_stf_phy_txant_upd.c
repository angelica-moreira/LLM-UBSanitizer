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
struct brcms_c_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  _brcms_c_stf_phy_txant_upd (struct brcms_c_info*) ; 

void brcms_c_stf_phy_txant_upd(struct brcms_c_info *wlc)
{
	_brcms_c_stf_phy_txant_upd(wlc);
}