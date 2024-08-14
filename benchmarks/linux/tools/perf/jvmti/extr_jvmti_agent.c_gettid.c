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
typedef  int /*<<< orphan*/  pid_t ;

/* Variables and functions */
 int /*<<< orphan*/  __NR_gettid ; 
 int /*<<< orphan*/  syscall (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline pid_t gettid(void)
{
	return (pid_t)syscall(__NR_gettid);
}