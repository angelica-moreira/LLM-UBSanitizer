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
struct dma_chan {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  to_virt_chan (struct dma_chan*) ; 
 int /*<<< orphan*/  vchan_synchronize (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void uniphier_mdmac_synchronize(struct dma_chan *chan)
{
	vchan_synchronize(to_virt_chan(chan));
}