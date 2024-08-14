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
 int /*<<< orphan*/  error_cnt ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  pass_cnt ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static int count_result(int err)
{
	if (err)
		error_cnt++;
	else
		pass_cnt++;

	fprintf(stderr, "\n");
	return err;
}