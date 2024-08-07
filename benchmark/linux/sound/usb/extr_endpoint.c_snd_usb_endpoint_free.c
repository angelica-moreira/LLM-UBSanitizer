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
struct snd_usb_endpoint {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct snd_usb_endpoint*) ; 

void snd_usb_endpoint_free(struct snd_usb_endpoint *ep)
{
	kfree(ep);
}