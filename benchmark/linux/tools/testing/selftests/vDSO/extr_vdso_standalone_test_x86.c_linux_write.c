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
 int /*<<< orphan*/  __NR_write ; 
 long x86_syscall3 (int /*<<< orphan*/ ,int,long,long) ; 

__attribute__((used)) static inline long linux_write(int fd, const void *data, size_t len)
{
	return x86_syscall3(__NR_write, fd, (long)data, (long)len);
}