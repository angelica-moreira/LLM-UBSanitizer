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
typedef  int u32 ;

/* Variables and functions */
 int EINVAL ; 
 int GMBUS_PIN_1_BXT ; 
 int GMBUS_PIN_2_BXT ; 
 int GMBUS_PIN_3_BXT ; 
 int GMBUS_PIN_4_CNP ; 
 int PORT_B ; 
 int PORT_C ; 
 int PORT_D ; 
 int PORT_E ; 
 int _GMBUS_PIN_SEL_MASK ; 

__attribute__((used)) static inline int cnp_get_port_from_gmbus0(u32 gmbus0)
{
	int port_select = gmbus0 & _GMBUS_PIN_SEL_MASK;
	int port = -EINVAL;

	if (port_select == GMBUS_PIN_1_BXT)
		port = PORT_B;
	else if (port_select == GMBUS_PIN_2_BXT)
		port = PORT_C;
	else if (port_select == GMBUS_PIN_3_BXT)
		port = PORT_D;
	else if (port_select == GMBUS_PIN_4_CNP)
		port = PORT_E;
	return port;
}