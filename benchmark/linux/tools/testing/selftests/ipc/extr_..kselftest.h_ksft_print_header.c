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
 int /*<<< orphan*/  getenv (char*) ; 
 int /*<<< orphan*/  printf (char*) ; 

__attribute__((used)) static inline void ksft_print_header(void)
{
	if (!(getenv("KSFT_TAP_LEVEL")))
		printf("TAP version 13\n");
}