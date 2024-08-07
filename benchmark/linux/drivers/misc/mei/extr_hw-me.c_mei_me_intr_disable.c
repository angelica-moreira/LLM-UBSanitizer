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
struct mei_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  me_intr_disable (struct mei_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mei_hcsr_read (struct mei_device*) ; 

__attribute__((used)) static void mei_me_intr_disable(struct mei_device *dev)
{
	u32 hcsr = mei_hcsr_read(dev);

	me_intr_disable(dev, hcsr);
}