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
struct usb_hcd {scalar_t__ hcd_priv; } ;
struct dummy_hcd {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline struct dummy_hcd *hcd_to_dummy_hcd(struct usb_hcd *hcd)
{
	return (struct dummy_hcd *) (hcd->hcd_priv);
}