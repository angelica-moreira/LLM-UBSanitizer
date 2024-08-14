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
 int MCL_CURRENT ; 
 int MCL_FUTURE ; 
 int MCL_ONFAULT ; 
 scalar_t__ mlockall (int) ; 
 int /*<<< orphan*/  munlockall () ; 
 int /*<<< orphan*/  perror (char*) ; 

__attribute__((used)) static int test_mlockall(int (test_function)(bool call_mlock))
{
	int ret = 1;

	if (mlockall(MCL_CURRENT | MCL_ONFAULT | MCL_FUTURE)) {
		perror("mlockall");
		return ret;
	}

	ret = test_function(false);
	munlockall();
	return ret;
}