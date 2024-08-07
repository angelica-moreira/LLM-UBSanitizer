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
struct hfc_multi {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  HFC_outb (struct hfc_multi*,int /*<<< orphan*/ ,unsigned char) ; 
 int /*<<< orphan*/  R_GPIO_OUT1 ; 

__attribute__((used)) static inline void
cpld_set_reg(struct hfc_multi *hc, unsigned char reg)
{
	/* Do data pin read low byte */
	HFC_outb(hc, R_GPIO_OUT1, reg);
}