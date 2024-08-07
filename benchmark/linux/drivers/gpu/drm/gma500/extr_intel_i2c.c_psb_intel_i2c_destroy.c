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
struct psb_intel_i2c_chan {int /*<<< orphan*/  adapter; } ;

/* Variables and functions */
 int /*<<< orphan*/  i2c_del_adapter (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct psb_intel_i2c_chan*) ; 

void psb_intel_i2c_destroy(struct psb_intel_i2c_chan *chan)
{
	if (!chan)
		return;

	i2c_del_adapter(&chan->adapter);
	kfree(chan);
}