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
struct dwc2_hsotg {int dummy; } ;

/* Variables and functions */
 int dwc2_gadget_exit_hibernation (struct dwc2_hsotg*,int,int) ; 
 int dwc2_host_exit_hibernation (struct dwc2_hsotg*,int,int) ; 

int dwc2_exit_hibernation(struct dwc2_hsotg *hsotg, int rem_wakeup,
			  int reset, int is_host)
{
	if (is_host)
		return dwc2_host_exit_hibernation(hsotg, rem_wakeup, reset);
	else
		return dwc2_gadget_exit_hibernation(hsotg, rem_wakeup, reset);
}