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
struct rk3066_hdmi {scalar_t__ regs; } ;

/* Variables and functions */
 int /*<<< orphan*/  writel_relaxed (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline void hdmi_writeb(struct rk3066_hdmi *hdmi, u16 offset, u32 val)
{
	writel_relaxed(val, hdmi->regs + offset);
}