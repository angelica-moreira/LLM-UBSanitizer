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
 int /*<<< orphan*/  close (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * event_fd ; 
 int /*<<< orphan*/ * prog_fd ; 

__attribute__((used)) static void unload_progs(void)
{
	close(prog_fd[0]);
	close(prog_fd[1]);
	close(event_fd[0]);
	close(event_fd[1]);
}