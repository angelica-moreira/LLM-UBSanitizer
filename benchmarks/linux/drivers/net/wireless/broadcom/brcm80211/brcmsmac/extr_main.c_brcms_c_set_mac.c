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
struct brcms_c_info {TYPE_1__* pub; } ;
struct brcms_bss_cfg {struct brcms_c_info* wlc; } ;
struct TYPE_2__ {int /*<<< orphan*/  cur_etheraddr; } ;

/* Variables and functions */
 int /*<<< orphan*/  RCM_MAC_OFFSET ; 
 int /*<<< orphan*/  brcms_c_ampdu_macaddr_upd (struct brcms_c_info*) ; 
 int /*<<< orphan*/  brcms_c_set_addrmatch (struct brcms_c_info*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int brcms_c_set_mac(struct brcms_bss_cfg *bsscfg)
{
	int err = 0;
	struct brcms_c_info *wlc = bsscfg->wlc;

	/* enter the MAC addr into the RXE match registers */
	brcms_c_set_addrmatch(wlc, RCM_MAC_OFFSET, wlc->pub->cur_etheraddr);

	brcms_c_ampdu_macaddr_upd(wlc);

	return err;
}