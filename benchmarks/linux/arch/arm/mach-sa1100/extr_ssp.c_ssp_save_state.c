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
struct ssp_state {int /*<<< orphan*/  cr1; int /*<<< orphan*/  cr0; } ;

/* Variables and functions */
 int /*<<< orphan*/  SSCR0_SSE ; 
 int /*<<< orphan*/  Ser4SSCR0 ; 
 int /*<<< orphan*/  Ser4SSCR1 ; 

void ssp_save_state(struct ssp_state *ssp)
{
	ssp->cr0 = Ser4SSCR0;
	ssp->cr1 = Ser4SSCR1;

	Ser4SSCR0 &= ~SSCR0_SSE;
}