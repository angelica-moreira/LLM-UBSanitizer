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
struct fotg210_hcd {TYPE_1__* regs; } ;
struct TYPE_2__ {int /*<<< orphan*/  otgcsr; } ;

/* Variables and functions */
 int OTGCSR_HOST_SPD_TYP ; 
 int readl (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline unsigned int
fotg210_get_speed(struct fotg210_hcd *fotg210, unsigned int portsc)
{
	return (readl(&fotg210->regs->otgcsr)
		& OTGCSR_HOST_SPD_TYP) >> 22;
}