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

__attribute__((used)) static inline int buf_roundup_len(struct sk_buff *skb)
{
	return (skb->len / 1024 + 1) * 1024;
}