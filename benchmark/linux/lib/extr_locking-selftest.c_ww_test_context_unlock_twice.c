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

/* Variables and functions */
 int /*<<< orphan*/  WWAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  WWAF (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  WWAI (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  t ; 

__attribute__((used)) static void ww_test_context_unlock_twice(void)
{
	WWAI(&t);
	WWAD(&t);
	WWAF(&t);
	WWAF(&t);
}