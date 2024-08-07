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
struct net_bridge {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BR_BOOLOPT_NO_LL_LEARN ; 
 int br_boolopt_toggle (struct net_bridge*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int set_no_linklocal_learn(struct net_bridge *br, unsigned long val)
{
	return br_boolopt_toggle(br, BR_BOOLOPT_NO_LL_LEARN, !!val, NULL);
}