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
 int MAXDEPTH ; 
 int /*<<< orphan*/  abort () ; 
 int depth ; 
 int /*<<< orphan*/  error (char*) ; 
 int /*<<< orphan*/  linenum ; 
 int /*<<< orphan*/ * stifline ; 

__attribute__((used)) static void
nest(void)
{
	if (depth > MAXDEPTH-1)
		abort(); /* bug */
	if (depth == MAXDEPTH-1)
		error("Too many levels of nesting");
	depth += 1;
	stifline[depth] = linenum;
}