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
struct xfrm_policy {int dummy; } ;

/* Variables and functions */
 scalar_t__ XFRM_POLICY_MAX ; 
 int /*<<< orphan*/  __xfrm_policy_link (struct xfrm_policy*,scalar_t__) ; 

__attribute__((used)) static void xfrm_sk_policy_link(struct xfrm_policy *pol, int dir)
{
	__xfrm_policy_link(pol, XFRM_POLICY_MAX + dir);
}