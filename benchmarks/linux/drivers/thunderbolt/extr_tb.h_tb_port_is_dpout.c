#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ type; } ;
struct tb_port {TYPE_1__ config; } ;

/* Variables and functions */
 scalar_t__ TB_TYPE_DP_HDMI_OUT ; 

__attribute__((used)) static inline bool tb_port_is_dpout(const struct tb_port *port)
{
	return port && port->config.type == TB_TYPE_DP_HDMI_OUT;
}