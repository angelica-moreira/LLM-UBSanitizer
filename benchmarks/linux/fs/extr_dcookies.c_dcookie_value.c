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
struct TYPE_2__ {scalar_t__ dentry; } ;
struct dcookie_struct {TYPE_1__ path; } ;

/* Variables and functions */

__attribute__((used)) static inline unsigned long dcookie_value(struct dcookie_struct * dcs)
{
	return (unsigned long)dcs->path.dentry;
}