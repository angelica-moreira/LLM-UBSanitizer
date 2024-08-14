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
struct lio {int /*<<< orphan*/  ifstate; } ;

/* Variables and functions */
 int atomic_read (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int ifstate_check(struct lio *lio, int state_flag)
{
	return atomic_read(&lio->ifstate) & state_flag;
}