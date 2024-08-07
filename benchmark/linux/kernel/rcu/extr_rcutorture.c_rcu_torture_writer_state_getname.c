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
 unsigned int ARRAY_SIZE (char const**) ; 
 unsigned int READ_ONCE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rcu_torture_writer_state ; 
 char const** rcu_torture_writer_state_names ; 

__attribute__((used)) static const char *rcu_torture_writer_state_getname(void)
{
	unsigned int i = READ_ONCE(rcu_torture_writer_state);

	if (i >= ARRAY_SIZE(rcu_torture_writer_state_names))
		return "???";
	return rcu_torture_writer_state_names[i];
}