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
typedef  int /*<<< orphan*/  u16 ;
struct olpc_ec_priv {int /*<<< orphan*/  ec_wakeup_mask; } ;

/* Variables and functions */
 scalar_t__ WARN_ON (int) ; 
 struct olpc_ec_priv* ec_priv ; 

void olpc_ec_wakeup_set(u16 value)
{
	struct olpc_ec_priv *ec = ec_priv;

	if (WARN_ON(!ec))
		return;

	ec->ec_wakeup_mask |= value;
}