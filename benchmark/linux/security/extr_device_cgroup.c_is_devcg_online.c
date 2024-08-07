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
struct dev_cgroup {scalar_t__ behavior; } ;

/* Variables and functions */
 scalar_t__ DEVCG_DEFAULT_NONE ; 

__attribute__((used)) static inline bool is_devcg_online(const struct dev_cgroup *devcg)
{
	return (devcg->behavior != DEVCG_DEFAULT_NONE);
}