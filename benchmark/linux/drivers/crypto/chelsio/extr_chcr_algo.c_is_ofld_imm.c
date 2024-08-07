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
struct sk_buff {scalar_t__ len; } ;

/* Variables and functions */
 scalar_t__ SGE_MAX_WR_LEN ; 

__attribute__((used)) static inline int is_ofld_imm(const struct sk_buff *skb)
{
	return (skb->len <= SGE_MAX_WR_LEN);
}