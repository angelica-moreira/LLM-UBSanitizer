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
struct drmem_lmb {int dummy; } ;

/* Variables and functions */
 int dlpar_change_lmb_state (struct drmem_lmb*,int) ; 

__attribute__((used)) static int dlpar_online_lmb(struct drmem_lmb *lmb)
{
	return dlpar_change_lmb_state(lmb, true);
}