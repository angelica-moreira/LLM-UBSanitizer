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
struct flow_dissector_key_ip {int /*<<< orphan*/  ttl; int /*<<< orphan*/  tos; } ;

/* Variables and functions */
 int TCA_FLOWER_KEY_ENC_IP_TOS ; 
 int TCA_FLOWER_KEY_ENC_IP_TOS_MASK ; 
 int TCA_FLOWER_KEY_ENC_IP_TTL ; 
 int TCA_FLOWER_KEY_ENC_IP_TTL_MASK ; 
 int TCA_FLOWER_KEY_IP_TOS ; 
 int TCA_FLOWER_KEY_IP_TOS_MASK ; 
 int TCA_FLOWER_KEY_IP_TTL ; 
 int TCA_FLOWER_KEY_IP_TTL_MASK ; 
 scalar_t__ fl_dump_key_val (struct sk_buff*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int,int) ; 

__attribute__((used)) static int fl_dump_key_ip(struct sk_buff *skb, bool encap,
			  struct flow_dissector_key_ip *key,
			  struct flow_dissector_key_ip *mask)
{
	int tos_key = encap ? TCA_FLOWER_KEY_ENC_IP_TOS : TCA_FLOWER_KEY_IP_TOS;
	int ttl_key = encap ? TCA_FLOWER_KEY_ENC_IP_TTL : TCA_FLOWER_KEY_IP_TTL;
	int tos_mask = encap ? TCA_FLOWER_KEY_ENC_IP_TOS_MASK : TCA_FLOWER_KEY_IP_TOS_MASK;
	int ttl_mask = encap ? TCA_FLOWER_KEY_ENC_IP_TTL_MASK : TCA_FLOWER_KEY_IP_TTL_MASK;

	if (fl_dump_key_val(skb, &key->tos, tos_key, &mask->tos, tos_mask, sizeof(key->tos)) ||
	    fl_dump_key_val(skb, &key->ttl, ttl_key, &mask->ttl, ttl_mask, sizeof(key->ttl)))
		return -1;

	return 0;
}