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
struct addr_location {int /*<<< orphan*/  thread; } ;

/* Variables and functions */
 int /*<<< orphan*/  thread__zput (int /*<<< orphan*/ ) ; 

void addr_location__put(struct addr_location *al)
{
	thread__zput(al->thread);
}