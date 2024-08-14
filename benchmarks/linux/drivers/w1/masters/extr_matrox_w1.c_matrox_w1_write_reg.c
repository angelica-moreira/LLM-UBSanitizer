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
typedef  int /*<<< orphan*/  u8 ;
struct matrox_device {int /*<<< orphan*/  port_data; int /*<<< orphan*/  port_index; } ;

/* Variables and functions */
 int /*<<< orphan*/  wmb () ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static __inline__ void matrox_w1_write_reg(struct matrox_device *dev, u8 reg, u8 val)
{
	writeb(reg, dev->port_index);
	writeb(val, dev->port_data);
	wmb();
}