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
 int /*<<< orphan*/  EXIT_SUCCESS ; 
 int /*<<< orphan*/  _exit (int /*<<< orphan*/ ) ; 
 int getpid () ; 
 int /*<<< orphan*/  printf (char*,int) ; 

__attribute__((used)) static int do_child(void *args)
{
	printf("%d\n", getpid());
	_exit(EXIT_SUCCESS);
}