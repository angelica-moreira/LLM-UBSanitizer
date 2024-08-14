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
struct iss_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ISP5_IRQENABLE_CLR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OMAP4_ISS_MEM_ISP_SYS1 ; 
 int /*<<< orphan*/  iss_reg_write (struct iss_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void omap4iss_isp_disable_interrupts(struct iss_device *iss)
{
	iss_reg_write(iss, OMAP4_ISS_MEM_ISP_SYS1, ISP5_IRQENABLE_CLR(0), ~0);
}