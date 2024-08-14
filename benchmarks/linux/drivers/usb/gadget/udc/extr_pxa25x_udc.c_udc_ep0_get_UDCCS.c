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
struct pxa25x_udc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  UDCCS0 ; 
 int /*<<< orphan*/  udc_get_reg (struct pxa25x_udc*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u32 udc_ep0_get_UDCCS(struct pxa25x_udc *dev)
{
	return udc_get_reg(dev, UDCCS0);
}