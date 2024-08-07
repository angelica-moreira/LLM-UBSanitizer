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
struct nlattr {int dummy; } ;
struct netns_ipvs {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 size_t IPVS_DAEMON_ATTR_STATE ; 
 int /*<<< orphan*/  nla_get_u32 (struct nlattr*) ; 
 int stop_sync_thread (struct netns_ipvs*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ip_vs_genl_del_daemon(struct netns_ipvs *ipvs, struct nlattr **attrs)
{
	int ret;

	if (!attrs[IPVS_DAEMON_ATTR_STATE])
		return -EINVAL;

	ret = stop_sync_thread(ipvs,
			       nla_get_u32(attrs[IPVS_DAEMON_ATTR_STATE]));
	return ret;
}