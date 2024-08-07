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
struct usbnet {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  restore_key (struct usbnet*,int) ; 

__attribute__((used)) static void restore_keys(struct usbnet *usbdev)
{
	int i;

	for (i = 0; i < 4; i++)
		restore_key(usbdev, i);
}