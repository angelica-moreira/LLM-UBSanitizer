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
struct sk_buff {int len; } ;

/* Variables and functions */
 int NFP_FLOWER_CMSG_HLEN ; 

__attribute__((used)) static inline int nfp_flower_cmsg_get_data_len(struct sk_buff *skb)
{
	return skb->len - NFP_FLOWER_CMSG_HLEN;
}