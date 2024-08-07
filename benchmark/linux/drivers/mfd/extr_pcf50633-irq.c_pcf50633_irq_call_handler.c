#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct pcf50633 {TYPE_1__* irq_handler; } ;
struct TYPE_2__ {int /*<<< orphan*/  data; int /*<<< orphan*/  (* handler ) (int,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void pcf50633_irq_call_handler(struct pcf50633 *pcf, int irq)
{
	if (pcf->irq_handler[irq].handler)
		pcf->irq_handler[irq].handler(irq, pcf->irq_handler[irq].data);
}