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
struct test_state {int attached; int /*<<< orphan*/  ctx; int /*<<< orphan*/  handle; } ;

/* Variables and functions */
 int /*<<< orphan*/  libusb_attach_kernel_driver (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  libusb_close (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  libusb_exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  libusb_release_interface (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void test_exit(struct test_state *state)
{
	libusb_release_interface(state->handle, 0);
	if (state->attached == 1)
		libusb_attach_kernel_driver(state->handle, 0);
	libusb_close(state->handle);
	libusb_exit(state->ctx);
}