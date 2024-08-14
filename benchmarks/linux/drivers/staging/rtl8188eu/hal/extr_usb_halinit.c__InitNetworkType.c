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
typedef  int u32 ;
struct adapter {int dummy; } ;

/* Variables and functions */
 int MASK_NETTYPE ; 
 int /*<<< orphan*/  NT_LINK_AP ; 
 int /*<<< orphan*/  REG_CR ; 
 int _NETTYPE (int /*<<< orphan*/ ) ; 
 int usb_read32 (struct adapter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_write32 (struct adapter*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void _InitNetworkType(struct adapter *Adapter)
{
	u32 value32;

	value32 = usb_read32(Adapter, REG_CR);
	/*  TODO: use the other function to set network type */
	value32 = (value32 & ~MASK_NETTYPE) | _NETTYPE(NT_LINK_AP);

	usb_write32(Adapter, REG_CR, value32);
}