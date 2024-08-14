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
struct sfp {int dummy; } ;

/* Variables and functions */
 unsigned int SFP_F_PRESENT ; 
 unsigned int sfp_gpio_get_state (struct sfp*) ; 

__attribute__((used)) static unsigned int sff_gpio_get_state(struct sfp *sfp)
{
	return sfp_gpio_get_state(sfp) | SFP_F_PRESENT;
}