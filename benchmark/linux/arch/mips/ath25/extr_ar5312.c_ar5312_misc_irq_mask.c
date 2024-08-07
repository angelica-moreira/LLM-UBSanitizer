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
struct irq_data {int /*<<< orphan*/  hwirq; } ;

/* Variables and functions */
 int /*<<< orphan*/  AR5312_IMR ; 
 int /*<<< orphan*/  BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ar5312_rst_reg_mask (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ar5312_rst_reg_read (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ar5312_misc_irq_mask(struct irq_data *d)
{
	ar5312_rst_reg_mask(AR5312_IMR, BIT(d->hwirq), 0);
	ar5312_rst_reg_read(AR5312_IMR); /* flush write buffer */
}