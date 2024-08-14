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
struct parport {int muxport; } ;

/* Variables and functions */
 int cpp_mux (struct parport*,int) ; 

__attribute__((used)) static int select_port(struct parport *port)
{
	int muxport = port->muxport;
	return cpp_mux(port, 0x60 + muxport) == muxport;
}