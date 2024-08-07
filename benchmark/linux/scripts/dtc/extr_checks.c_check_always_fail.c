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
struct node {int dummy; } ;
struct dt_info {int dummy; } ;
struct check {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  FAIL (struct check*,struct dt_info*,struct node*,char*) ; 

__attribute__((used)) static inline void check_always_fail(struct check *c, struct dt_info *dti,
				     struct node *node)
{
	FAIL(c, dti, node, "always_fail check");
}