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
struct mxl111sf_state {int port_expander_addr; int gpio_port_expander; } ;

/* Variables and functions */
 int /*<<< orphan*/  KERN_ERR ; 
#define  mxl111sf_PCA9534 129 
#define  mxl111sf_gpio_hw 128 
 int mxl111sf_hw_gpio_initialize (struct mxl111sf_state*) ; 
 int /*<<< orphan*/  mxl111sf_probe_port_expander (struct mxl111sf_state*) ; 
 int /*<<< orphan*/  mxl_debug (char*) ; 
 int /*<<< orphan*/  mxl_printk (int /*<<< orphan*/ ,char*) ; 
 int pca9534_init_port_expander (struct mxl111sf_state*) ; 

int mxl111sf_init_port_expander(struct mxl111sf_state *state)
{
	mxl_debug("()");

	if (0x00 == state->port_expander_addr)
		mxl111sf_probe_port_expander(state);

	switch (state->gpio_port_expander) {
	default:
		mxl_printk(KERN_ERR,
			   "gpio_port_expander undefined, assuming PCA9534");
		/* fall-thru */
	case mxl111sf_PCA9534:
		return pca9534_init_port_expander(state);
	case mxl111sf_gpio_hw:
		return mxl111sf_hw_gpio_initialize(state);
	}
}