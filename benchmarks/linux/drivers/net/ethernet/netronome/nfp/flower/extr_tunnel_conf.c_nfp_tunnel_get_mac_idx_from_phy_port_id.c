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
typedef  int u16 ;

/* Variables and functions */
 int NFP_FLOWER_CMSG_PORT_TYPE_PHYS_PORT ; 

__attribute__((used)) static u16 nfp_tunnel_get_mac_idx_from_phy_port_id(int port)
{
	return port << 8 | NFP_FLOWER_CMSG_PORT_TYPE_PHYS_PORT;
}