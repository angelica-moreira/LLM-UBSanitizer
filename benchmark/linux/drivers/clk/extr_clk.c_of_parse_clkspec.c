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
struct of_phandle_args {int dummy; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int ENOENT ; 

__attribute__((used)) static inline int of_parse_clkspec(const struct device_node *np, int index,
				   const char *name,
				   struct of_phandle_args *out_args)
{
	return -ENOENT;
}