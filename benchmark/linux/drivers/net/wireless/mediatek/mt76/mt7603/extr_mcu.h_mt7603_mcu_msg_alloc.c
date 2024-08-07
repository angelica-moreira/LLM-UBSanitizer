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
struct mt7603_mcu_txd {int dummy; } ;

/* Variables and functions */
 struct sk_buff* mt76_mcu_msg_alloc (void const*,int,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct sk_buff *
mt7603_mcu_msg_alloc(const void *data, int len)
{
	return mt76_mcu_msg_alloc(data, sizeof(struct mt7603_mcu_txd),
				  len, 0);
}