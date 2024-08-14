#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {unsigned int flags; } ;

/* Variables and functions */
 TYPE_1__ amd_northbridges ; 

bool amd_nb_has_feature(unsigned int feature)
{
	return ((amd_northbridges.flags & feature) == feature);
}