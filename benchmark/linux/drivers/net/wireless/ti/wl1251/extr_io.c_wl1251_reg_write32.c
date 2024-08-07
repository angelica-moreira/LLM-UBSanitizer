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
typedef  int /*<<< orphan*/  u32 ;
struct wl1251 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  wl1251_translate_reg_addr (struct wl1251*,int) ; 
 int /*<<< orphan*/  wl1251_write32 (struct wl1251*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void wl1251_reg_write32(struct wl1251 *wl, int addr, u32 val)
{
	wl1251_write32(wl, wl1251_translate_reg_addr(wl, addr), val);
}