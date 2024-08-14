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
typedef  union ieee754dp {int dummy; } ieee754dp ;

/* Variables and functions */
 union ieee754dp ieee754dp_div (int /*<<< orphan*/ ,union ieee754dp) ; 
 int /*<<< orphan*/  ieee754dp_one (int /*<<< orphan*/ ) ; 

__attribute__((used)) static union ieee754dp fpemu_dp_recip(union ieee754dp d)
{
	return ieee754dp_div(ieee754dp_one(0), d);
}