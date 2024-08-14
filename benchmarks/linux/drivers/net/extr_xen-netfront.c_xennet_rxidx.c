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
typedef  int RING_IDX ;

/* Variables and functions */
 int NET_RX_RING_SIZE ; 

__attribute__((used)) static int xennet_rxidx(RING_IDX idx)
{
	return idx & (NET_RX_RING_SIZE - 1);
}