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
typedef  int u32 ;
struct mei_device {int dummy; } ;

/* Variables and functions */
 int H_CSR_IE_MASK ; 
 int H_IG ; 
 int H_RDY ; 
 int mei_hcsr_read (struct mei_device*) ; 
 int /*<<< orphan*/  mei_hcsr_set (struct mei_device*,int) ; 

__attribute__((used)) static void mei_me_host_set_ready(struct mei_device *dev)
{
	u32 hcsr = mei_hcsr_read(dev);

	hcsr |= H_CSR_IE_MASK | H_IG | H_RDY;
	mei_hcsr_set(dev, hcsr);
}