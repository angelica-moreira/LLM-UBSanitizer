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
struct mac_iop {int /*<<< orphan*/  status_ctrl; } ;

/* Variables and functions */
 int /*<<< orphan*/  IOP_IRQ ; 

__attribute__((used)) static __inline__ void iop_interrupt(volatile struct mac_iop *iop)
{
	iop->status_ctrl |= IOP_IRQ;
}