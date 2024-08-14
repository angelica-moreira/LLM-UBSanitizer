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
struct parport {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __parport_gsc_frob_control (struct parport*,int,int) ; 

__attribute__((used)) static inline void parport_gsc_disable_irq(struct parport *p)
{
	__parport_gsc_frob_control (p, 0x10, 0x00);
}