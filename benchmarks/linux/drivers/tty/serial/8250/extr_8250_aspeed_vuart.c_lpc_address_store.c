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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct aspeed_vuart {scalar_t__ regs; } ;
typedef  int ssize_t ;

/* Variables and functions */
 scalar_t__ ASPEED_VUART_ADDRH ; 
 scalar_t__ ASPEED_VUART_ADDRL ; 
 struct aspeed_vuart* dev_get_drvdata (struct device*) ; 
 int kstrtoul (char const*,int /*<<< orphan*/ ,unsigned long*) ; 
 int /*<<< orphan*/  writeb (unsigned long,scalar_t__) ; 

__attribute__((used)) static ssize_t lpc_address_store(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf, size_t count)
{
	struct aspeed_vuart *vuart = dev_get_drvdata(dev);
	unsigned long val;
	int err;

	err = kstrtoul(buf, 0, &val);
	if (err)
		return err;

	writeb(val >> 8, vuart->regs + ASPEED_VUART_ADDRH);
	writeb(val >> 0, vuart->regs + ASPEED_VUART_ADDRL);

	return count;
}