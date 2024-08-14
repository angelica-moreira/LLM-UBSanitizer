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
 int /*<<< orphan*/  ENOSYS ; 
 int /*<<< orphan*/  __NR_mlock2 ; 
 int /*<<< orphan*/  errno ; 
 int syscall (int /*<<< orphan*/ ,void*,size_t,int) ; 

__attribute__((used)) static int mlock2_(void *start, size_t len, int flags)
{
#ifdef __NR_mlock2
	return syscall(__NR_mlock2, start, len, flags);
#else
	errno = ENOSYS;
	return -1;
#endif
}