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
struct pch_udc_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  UDC_DEVSTS_ADDR ; 
 int /*<<< orphan*/  pch_udc_readl (struct pch_udc_dev*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u32 pch_udc_read_device_status(struct pch_udc_dev *dev)
{
	return pch_udc_readl(dev, UDC_DEVSTS_ADDR);
}