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
struct mt76_dev {int dummy; } ;

/* Variables and functions */
 int mt76_chip (struct mt76_dev*) ; 

__attribute__((used)) static inline bool is_mt7622(struct mt76_dev *dev)
{
	return mt76_chip(dev) == 0x7622;
}