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
struct qeth_card {TYPE_1__* gdev; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  IPA_IPV6 ; 
 int /*<<< orphan*/  QETH_CARD_IFNAME (struct qeth_card*) ; 
 int /*<<< orphan*/  QETH_CARD_TEXT (struct qeth_card*,int,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  qeth_is_supported (struct qeth_card*,int /*<<< orphan*/ ) ; 
 int qeth_l3_softsetup_ipv6 (struct qeth_card*) ; 

__attribute__((used)) static int qeth_l3_start_ipa_ipv6(struct qeth_card *card)
{
	QETH_CARD_TEXT(card, 3, "strtipv6");

	if (!qeth_is_supported(card, IPA_IPV6)) {
		dev_info(&card->gdev->dev,
			"IPv6 not supported on %s\n", QETH_CARD_IFNAME(card));
		return 0;
	}
	return qeth_l3_softsetup_ipv6(card);
}