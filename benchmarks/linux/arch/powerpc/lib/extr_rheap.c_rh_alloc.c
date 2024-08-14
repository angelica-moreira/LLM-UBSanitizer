#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  alignment; } ;
typedef  TYPE_1__ rh_info_t ;

/* Variables and functions */
 unsigned long rh_alloc_align (TYPE_1__*,int,int /*<<< orphan*/ ,char const*) ; 

unsigned long rh_alloc(rh_info_t * info, int size, const char *owner)
{
	return rh_alloc_align(info, size, info->alignment, owner);
}