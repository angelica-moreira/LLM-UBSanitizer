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
struct usnic_vnic {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct usnic_vnic*) ; 
 int /*<<< orphan*/  usnic_vnic_release_resources (struct usnic_vnic*) ; 

void usnic_vnic_free(struct usnic_vnic *vnic)
{
	usnic_vnic_release_resources(vnic);
	kfree(vnic);
}