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
struct net_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AQ_CFG_RSS_INDIRECTION_TABLE_MAX ; 

__attribute__((used)) static u32 aq_ethtool_get_rss_indir_size(struct net_device *ndev)
{
	return AQ_CFG_RSS_INDIRECTION_TABLE_MAX;
}