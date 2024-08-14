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
struct usb_desc_validator {int dummy; } ;
struct uac3_feature_unit_descriptor {int bLength; } ;

/* Variables and functions */

__attribute__((used)) static bool validate_uac3_feature_unit(const void *p,
				       const struct usb_desc_validator *v)
{
	const struct uac3_feature_unit_descriptor *d = p;

	if (d->bLength < sizeof(*d))
		return false;
	/* at least bmaControls(0) for master channel + wFeatureDescrStr */
	return d->bLength >= sizeof(*d) + 4 + 2;
}