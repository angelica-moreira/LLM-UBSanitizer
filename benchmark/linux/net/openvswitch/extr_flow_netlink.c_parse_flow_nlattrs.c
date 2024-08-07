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
typedef  int /*<<< orphan*/  u64 ;
struct nlattr {int dummy; } ;

/* Variables and functions */
 int __parse_flow_nlattrs (struct nlattr const*,struct nlattr const**,int /*<<< orphan*/ *,int,int) ; 

int parse_flow_nlattrs(const struct nlattr *attr, const struct nlattr *a[],
		       u64 *attrsp, bool log)
{
	return __parse_flow_nlattrs(attr, a, attrsp, log, false);
}