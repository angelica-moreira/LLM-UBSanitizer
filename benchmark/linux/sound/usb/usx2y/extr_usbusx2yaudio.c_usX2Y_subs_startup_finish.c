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
struct usX2Ydev {int /*<<< orphan*/ * prepare_subs; } ;

/* Variables and functions */
 int /*<<< orphan*/  i_usX2Y_urb_complete ; 
 int /*<<< orphan*/  usX2Y_urbs_set_complete (struct usX2Ydev*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void usX2Y_subs_startup_finish(struct usX2Ydev * usX2Y)
{
	usX2Y_urbs_set_complete(usX2Y, i_usX2Y_urb_complete);
	usX2Y->prepare_subs = NULL;
}