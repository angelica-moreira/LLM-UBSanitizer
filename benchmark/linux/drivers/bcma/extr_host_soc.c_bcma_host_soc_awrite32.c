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
typedef  scalar_t__ u16 ;
struct bcma_device {scalar_t__ io_wrap; } ;

/* Variables and functions */
 scalar_t__ WARN_ONCE (int,char*) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void bcma_host_soc_awrite32(struct bcma_device *core, u16 offset,
				  u32 value)
{
	if (WARN_ONCE(!core->io_wrap, "Accessed core has no wrapper/agent\n"))
		return;
	writel(value, core->io_wrap + offset);
}