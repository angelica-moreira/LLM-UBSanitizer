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
struct ib_mad_agent_private {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline int ib_mad_enforce_security(struct ib_mad_agent_private *map,
					  u16 pkey_index)
{
	return 0;
}