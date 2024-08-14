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
struct parport {size_t number; } ;

/* Variables and functions */
 int /*<<< orphan*/  MKDEV (int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  PP_MAJOR ; 
 int /*<<< orphan*/  device_destroy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ ** devices ; 
 int /*<<< orphan*/  ppdev_class ; 

__attribute__((used)) static void pp_detach(struct parport *port)
{
	if (!devices[port->number])
		return;

	device_destroy(ppdev_class, MKDEV(PP_MAJOR, port->number));
	devices[port->number] = NULL;
}