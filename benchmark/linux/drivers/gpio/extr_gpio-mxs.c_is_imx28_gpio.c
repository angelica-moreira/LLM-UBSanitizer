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
struct mxs_gpio_port {scalar_t__ devid; } ;

/* Variables and functions */
 scalar_t__ IMX28_GPIO ; 

__attribute__((used)) static inline int is_imx28_gpio(struct mxs_gpio_port *port)
{
	return port->devid == IMX28_GPIO;
}