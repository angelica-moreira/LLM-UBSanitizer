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
typedef  int /*<<< orphan*/  u32 ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  I40E_HLUT_ARRAY_SIZE ; 

__attribute__((used)) static u32 i40e_get_rxfh_indir_size(struct net_device *netdev)
{
	return I40E_HLUT_ARRAY_SIZE;
}