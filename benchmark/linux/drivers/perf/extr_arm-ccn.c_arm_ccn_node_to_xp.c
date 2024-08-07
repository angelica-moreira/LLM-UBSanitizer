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

/* Variables and functions */
 int CCN_NUM_XP_PORTS ; 

__attribute__((used)) static int arm_ccn_node_to_xp(int node)
{
	return node / CCN_NUM_XP_PORTS;
}