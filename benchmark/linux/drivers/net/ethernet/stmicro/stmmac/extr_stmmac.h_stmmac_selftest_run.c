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
typedef  int /*<<< orphan*/  u64 ;
struct net_device {int dummy; } ;
struct ethtool_test {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline void stmmac_selftest_run(struct net_device *dev,
				       struct ethtool_test *etest, u64 *buf)
{
	/* Not enabled */
}