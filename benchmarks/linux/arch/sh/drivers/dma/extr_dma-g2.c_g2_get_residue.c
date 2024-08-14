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
struct dma_channel {int /*<<< orphan*/  chan; } ;

/* Variables and functions */
 int g2_bytes_remaining (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int g2_get_residue(struct dma_channel *chan)
{
	return g2_bytes_remaining(chan->chan);
}