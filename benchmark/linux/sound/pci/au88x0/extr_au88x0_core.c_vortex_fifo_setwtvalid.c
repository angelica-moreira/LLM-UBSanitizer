#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  mmio; } ;
typedef  TYPE_1__ vortex_t ;

/* Variables and functions */
 int FIFO_U1 ; 
 scalar_t__ VORTEX_FIFO_WTCTRL ; 
 int hwread (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  hwwrite (int /*<<< orphan*/ ,scalar_t__,int) ; 

__attribute__((used)) static void vortex_fifo_setwtvalid(vortex_t * vortex, int fifo, int en)
{
	hwwrite(vortex->mmio, VORTEX_FIFO_WTCTRL + (fifo << 2),
		(hwread(vortex->mmio, VORTEX_FIFO_WTCTRL + (fifo << 2)) &
		 0xffffffef) | ((en & 1) << 4) | FIFO_U1);
}