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
struct irq_data {int irq; } ;
struct TYPE_2__ {int imask1; } ;

/* Variables and functions */
 int SGINT_LOCAL1 ; 
 TYPE_1__* sgint ; 

__attribute__((used)) static void disable_local1_irq(struct irq_data *d)
{
	sgint->imask1 &= ~(1 << (d->irq - SGINT_LOCAL1));
}