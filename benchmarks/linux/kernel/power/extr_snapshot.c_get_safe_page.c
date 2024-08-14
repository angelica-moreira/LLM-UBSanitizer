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
typedef  int /*<<< orphan*/  gfp_t ;

/* Variables and functions */
 scalar_t__ __get_safe_page (int /*<<< orphan*/ ) ; 

unsigned long get_safe_page(gfp_t gfp_mask)
{
	return (unsigned long)__get_safe_page(gfp_mask);
}