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

/* Variables and functions */
 int /*<<< orphan*/  MSP_INT_USB ; 
 int /*<<< orphan*/  do_IRQ (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void usb_int_dispatch(void)  { do_IRQ(MSP_INT_USB);  }