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
struct hclge_mac {int /*<<< orphan*/  supported; } ;
struct TYPE_3__ {struct hclge_mac mac; } ;
struct hclge_dev {TYPE_2__* pdev; TYPE_1__ hw; } ;
struct TYPE_4__ {int revision; } ;

/* Variables and functions */
 int /*<<< orphan*/  ETHTOOL_LINK_MODE_Backplane_BIT ; 
 int /*<<< orphan*/  ETHTOOL_LINK_MODE_FEC_NONE_BIT ; 
 int /*<<< orphan*/  ETHTOOL_LINK_MODE_Pause_BIT ; 
 int /*<<< orphan*/  hclge_convert_setting_fec (struct hclge_mac*) ; 
 int /*<<< orphan*/  hclge_convert_setting_kr (struct hclge_mac*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  linkmode_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void hclge_parse_backplane_link_mode(struct hclge_dev *hdev,
					    u8 speed_ability)
{
	struct hclge_mac *mac = &hdev->hw.mac;

	hclge_convert_setting_kr(mac, speed_ability);
	if (hdev->pdev->revision >= 0x21)
		hclge_convert_setting_fec(mac);
	linkmode_set_bit(ETHTOOL_LINK_MODE_Backplane_BIT, mac->supported);
	linkmode_set_bit(ETHTOOL_LINK_MODE_Pause_BIT, mac->supported);
	linkmode_set_bit(ETHTOOL_LINK_MODE_FEC_NONE_BIT, mac->supported);
}