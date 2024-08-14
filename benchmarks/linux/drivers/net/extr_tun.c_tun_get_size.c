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
typedef  int /*<<< orphan*/  uid_t ;
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct net_device {int dummy; } ;
typedef  int /*<<< orphan*/  gid_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 size_t nla_total_size (int) ; 

__attribute__((used)) static size_t tun_get_size(const struct net_device *dev)
{
	BUILD_BUG_ON(sizeof(u32) != sizeof(uid_t));
	BUILD_BUG_ON(sizeof(u32) != sizeof(gid_t));

	return nla_total_size(sizeof(uid_t)) + /* OWNER */
	       nla_total_size(sizeof(gid_t)) + /* GROUP */
	       nla_total_size(sizeof(u8)) + /* TYPE */
	       nla_total_size(sizeof(u8)) + /* PI */
	       nla_total_size(sizeof(u8)) + /* VNET_HDR */
	       nla_total_size(sizeof(u8)) + /* PERSIST */
	       nla_total_size(sizeof(u8)) + /* MULTI_QUEUE */
	       nla_total_size(sizeof(u32)) + /* NUM_QUEUES */
	       nla_total_size(sizeof(u32)) + /* NUM_DISABLED_QUEUES */
	       0;
}