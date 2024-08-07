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
typedef  union bpf_attr {int dummy; } bpf_attr ;
typedef  enum bpf_cmd { ____Placeholder_bpf_cmd } bpf_cmd ;

/* Variables and functions */
 int /*<<< orphan*/  __NR_bpf ; 
 int syscall (int /*<<< orphan*/ ,int,union bpf_attr*,unsigned int) ; 

__attribute__((used)) static inline int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr,
			  unsigned int size)
{
	return syscall(__NR_bpf, cmd, attr, size);
}