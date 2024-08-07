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
typedef  int u8 ;
struct device {int dummy; } ;
struct ci_hdrc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  OP_ULPI_VIEWPORT ; 
 int ULPI_ADDR (int) ; 
 int ULPI_RUN ; 
 int ULPI_WAKEUP ; 
 int ULPI_WRITE ; 
 int ci_ulpi_wait (struct ci_hdrc*,int) ; 
 struct ci_hdrc* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  hw_write (struct ci_hdrc*,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static int ci_ulpi_write(struct device *dev, u8 addr, u8 val)
{
	struct ci_hdrc *ci = dev_get_drvdata(dev);
	int ret;

	hw_write(ci, OP_ULPI_VIEWPORT, 0xffffffff, ULPI_WRITE | ULPI_WAKEUP);
	ret = ci_ulpi_wait(ci, ULPI_WAKEUP);
	if (ret)
		return ret;

	hw_write(ci, OP_ULPI_VIEWPORT, 0xffffffff,
		 ULPI_RUN | ULPI_WRITE | ULPI_ADDR(addr) | val);
	return ci_ulpi_wait(ci, ULPI_RUN);
}