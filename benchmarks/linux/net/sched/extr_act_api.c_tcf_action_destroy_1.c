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
struct tc_action {int dummy; } ;

/* Variables and functions */
 int tcf_action_destroy (struct tc_action**,int) ; 

__attribute__((used)) static int tcf_action_destroy_1(struct tc_action *a, int bind)
{
	struct tc_action *actions[] = { a, NULL };

	return tcf_action_destroy(actions, bind);
}