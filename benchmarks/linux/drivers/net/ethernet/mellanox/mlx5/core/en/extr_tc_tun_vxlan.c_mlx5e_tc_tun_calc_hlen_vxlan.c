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
struct mlx5e_encap_entry {int dummy; } ;

/* Variables and functions */
 int VXLAN_HLEN ; 

__attribute__((used)) static int mlx5e_tc_tun_calc_hlen_vxlan(struct mlx5e_encap_entry *e)
{
	return VXLAN_HLEN;
}