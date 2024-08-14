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
typedef  int u8 ;
struct rt2x00_dev {int dummy; } ;

/* Variables and functions */
 int rt2800_rfcsr_read (struct rt2x00_dev*,unsigned int const) ; 

__attribute__((used)) static u8 rt2800_rfcsr_read_bank(struct rt2x00_dev *rt2x00dev, const u8 bank,
				 const unsigned int reg)
{
	return rt2800_rfcsr_read(rt2x00dev, (reg | (bank << 6)));
}