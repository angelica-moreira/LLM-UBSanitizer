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
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  u16 ;
struct ib_device {int dummy; } ;

/* Variables and functions */
 int ib_get_cached_pkey (struct ib_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int ib_get_cached_subnet_prefix (struct ib_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rdma_protocol_ib (struct ib_device*,int /*<<< orphan*/ ) ; 
 int security_ib_pkey_access (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ib_security_pkey_access(struct ib_device *dev,
				   u8 port_num,
				   u16 pkey_index,
				   void *sec)
{
	u64 subnet_prefix;
	u16 pkey;
	int ret;

	if (!rdma_protocol_ib(dev, port_num))
		return 0;

	ret = ib_get_cached_pkey(dev, port_num, pkey_index, &pkey);
	if (ret)
		return ret;

	ret = ib_get_cached_subnet_prefix(dev, port_num, &subnet_prefix);

	if (ret)
		return ret;

	return security_ib_pkey_access(sec, subnet_prefix, pkey);
}