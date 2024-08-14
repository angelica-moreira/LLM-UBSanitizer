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
struct gfar_private {int num_rx_queues; int /*<<< orphan*/ * rx_queue; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void gfar_free_rx_queues(struct gfar_private *priv)
{
	int i;

	for (i = 0; i < priv->num_rx_queues; i++)
		kfree(priv->rx_queue[i]);
}