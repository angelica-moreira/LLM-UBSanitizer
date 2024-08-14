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
struct sumo_ps {int dummy; } ;
struct radeon_ps {struct sumo_ps* ps_priv; } ;

/* Variables and functions */

__attribute__((used)) static struct sumo_ps *sumo_get_ps(struct radeon_ps *rps)
{
	struct sumo_ps *ps = rps->ps_priv;

	return ps;
}