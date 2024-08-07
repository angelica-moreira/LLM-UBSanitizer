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
struct sk_buff {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CRC_B_INIT ; 
 int /*<<< orphan*/  crc_ccitt ; 
 int digital_skb_check_crc (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int digital_skb_check_crc_b(struct sk_buff *skb)
{
	return digital_skb_check_crc(skb, crc_ccitt, CRC_B_INIT, 1, 0);
}