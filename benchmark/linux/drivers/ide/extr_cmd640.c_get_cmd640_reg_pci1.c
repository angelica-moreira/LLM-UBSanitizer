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
typedef  int u16 ;

/* Variables and functions */
 int cmd640_key ; 
 int /*<<< orphan*/  inb_p (int) ; 
 int /*<<< orphan*/  outl_p (int,int) ; 

__attribute__((used)) static u8 get_cmd640_reg_pci1(u16 reg)
{
	outl_p((reg & 0xfc) | cmd640_key, 0xcf8);
	return inb_p((reg & 3) | 0xcfc);
}