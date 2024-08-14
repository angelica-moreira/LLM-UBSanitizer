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
typedef  int /*<<< orphan*/  u8 ;
struct ite_dev {scalar_t__ cir_addr; } ;

/* Variables and functions */
 scalar_t__ IT8708_C0DR ; 
 int /*<<< orphan*/  outb (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void it8708_put_tx_byte(struct ite_dev *dev, u8 value)
{
	outb(value, dev->cir_addr + IT8708_C0DR);
}