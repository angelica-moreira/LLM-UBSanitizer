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
struct wl1251 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  wl1251_spi_reset (struct wl1251*) ; 
 int /*<<< orphan*/  wl1251_spi_wake (struct wl1251*) ; 

__attribute__((used)) static void wl1251_spi_reset_wake(struct wl1251 *wl)
{
	wl1251_spi_reset(wl);
	wl1251_spi_wake(wl);
}