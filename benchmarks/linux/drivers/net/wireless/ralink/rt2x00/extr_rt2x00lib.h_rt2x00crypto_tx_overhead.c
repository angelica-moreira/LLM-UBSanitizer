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
struct rt2x00_dev {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline unsigned int rt2x00crypto_tx_overhead(struct rt2x00_dev *rt2x00dev,
						    struct sk_buff *skb)
{
	return 0;
}