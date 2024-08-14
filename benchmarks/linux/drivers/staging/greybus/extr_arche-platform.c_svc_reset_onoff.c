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
struct gpio_desc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  gpiod_set_raw_value (struct gpio_desc*,int) ; 

__attribute__((used)) static inline void svc_reset_onoff(struct gpio_desc *gpio, bool onoff)
{
	gpiod_set_raw_value(gpio, onoff);
}