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
typedef  enum pvrdma_port_state { ____Placeholder_pvrdma_port_state } pvrdma_port_state ;
typedef  enum ib_port_state { ____Placeholder_ib_port_state } ib_port_state ;

/* Variables and functions */

__attribute__((used)) static inline enum pvrdma_port_state ib_port_state_to_pvrdma(
					enum ib_port_state state)
{
	return (enum pvrdma_port_state)state;
}