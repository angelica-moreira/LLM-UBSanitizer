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
struct option {int dummy; } ;

/* Variables and functions */
 int parse_options_subcommand (int,char const**,struct option const*,int /*<<< orphan*/ *,char const**,int) ; 

int parse_options(int argc, const char **argv, const struct option *options,
		  const char * const usagestr[], int flags)
{
	return parse_options_subcommand(argc, argv, options, NULL,
					(const char **) usagestr, flags);
}