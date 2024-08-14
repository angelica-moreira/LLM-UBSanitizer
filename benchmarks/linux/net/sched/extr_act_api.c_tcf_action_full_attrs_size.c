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
struct tcamsg {int dummy; } ;

/* Variables and functions */
 size_t NLMSG_HDRLEN ; 
 size_t nla_total_size (int /*<<< orphan*/ ) ; 

__attribute__((used)) static size_t tcf_action_full_attrs_size(size_t sz)
{
	return NLMSG_HDRLEN                     /* struct nlmsghdr */
		+ sizeof(struct tcamsg)
		+ nla_total_size(0)             /* TCA_ACT_TAB nested */
		+ sz;
}