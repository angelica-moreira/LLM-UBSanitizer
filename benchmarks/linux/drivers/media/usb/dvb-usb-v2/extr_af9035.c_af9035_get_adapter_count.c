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
struct state {int dual_mode; } ;
struct dvb_usb_device {int dummy; } ;

/* Variables and functions */
 struct state* d_to_priv (struct dvb_usb_device*) ; 

__attribute__((used)) static int af9035_get_adapter_count(struct dvb_usb_device *d)
{
	struct state *state = d_to_priv(d);

	return state->dual_mode + 1;
}