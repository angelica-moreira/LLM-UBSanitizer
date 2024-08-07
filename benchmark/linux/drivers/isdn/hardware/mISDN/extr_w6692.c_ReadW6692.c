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
typedef  scalar_t__ u8 ;
struct w6692_hw {scalar_t__ addr; } ;

/* Variables and functions */
 scalar_t__ inb (scalar_t__) ; 

__attribute__((used)) static inline u8
ReadW6692(struct w6692_hw *card, u8 offset)
{
	return inb(card->addr + offset);
}