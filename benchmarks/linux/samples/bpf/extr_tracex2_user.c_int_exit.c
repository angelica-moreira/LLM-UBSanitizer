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
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * map_fd ; 
 int /*<<< orphan*/  print_hist (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void int_exit(int sig)
{
	print_hist(map_fd[1]);
	exit(0);
}