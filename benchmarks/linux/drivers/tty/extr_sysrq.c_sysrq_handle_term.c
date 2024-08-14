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
 int /*<<< orphan*/  CONSOLE_LOGLEVEL_DEBUG ; 
 int /*<<< orphan*/  SIGTERM ; 
 int /*<<< orphan*/  console_loglevel ; 
 int /*<<< orphan*/  send_sig_all (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sysrq_handle_term(int key)
{
	send_sig_all(SIGTERM);
	console_loglevel = CONSOLE_LOGLEVEL_DEBUG;
}