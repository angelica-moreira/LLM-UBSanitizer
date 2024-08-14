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
struct task_struct {int dummy; } ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  FOLL_FORCE ; 
 int access_process_vm (struct task_struct*,unsigned long,int*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int
read_int(struct task_struct *task, unsigned long addr, int * data)
{
	int copied = access_process_vm(task, addr, data, sizeof(int),
			FOLL_FORCE);
	return (copied == sizeof(int)) ? 0 : -EIO;
}