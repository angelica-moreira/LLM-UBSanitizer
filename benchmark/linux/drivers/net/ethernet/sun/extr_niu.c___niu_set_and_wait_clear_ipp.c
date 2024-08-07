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
typedef  scalar_t__ u64 ;
struct niu {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int __niu_wait_bits_clear_ipp (struct niu*,unsigned long,scalar_t__,int,int) ; 
 int /*<<< orphan*/  netdev_err (int /*<<< orphan*/ ,char*,unsigned long long,char const*,unsigned long long) ; 
 scalar_t__ nr64_ipp (unsigned long) ; 
 int /*<<< orphan*/  nw64_ipp (unsigned long,scalar_t__) ; 

__attribute__((used)) static int __niu_set_and_wait_clear_ipp(struct niu *np, unsigned long reg,
					u64 bits, int limit, int delay,
					const char *reg_name)
{
	int err;
	u64 val;

	val = nr64_ipp(reg);
	val |= bits;
	nw64_ipp(reg, val);

	err = __niu_wait_bits_clear_ipp(np, reg, bits, limit, delay);
	if (err)
		netdev_err(np->dev, "bits (%llx) of register %s would not clear, val[%llx]\n",
			   (unsigned long long)bits, reg_name,
			   (unsigned long long)nr64_ipp(reg));
	return err;
}