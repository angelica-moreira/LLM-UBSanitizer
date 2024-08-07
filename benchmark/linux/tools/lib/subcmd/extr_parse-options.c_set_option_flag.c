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
struct option {int flags; } ;

/* Variables and functions */
 struct option* find_option (struct option*,int,char const*) ; 

void set_option_flag(struct option *opts, int shortopt, const char *longopt,
		     int flag)
{
	struct option *opt = find_option(opts, shortopt, longopt);

	if (opt)
		opt->flags |= flag;
	return;
}