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
 int /*<<< orphan*/  handled ; 
 int /*<<< orphan*/  perror (char*) ; 
 int write (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static void signal_handler(int signal)
{
	if (write(handled, "c", 1) != 1)
		perror("write from signal");
}