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
struct node {int basenamelen; int /*<<< orphan*/ * name; } ;
struct dt_info {int dummy; } ;
struct check {int /*<<< orphan*/  data; } ;

/* Variables and functions */
 int /*<<< orphan*/  FAIL (struct check*,struct dt_info*,struct node*,char*,int /*<<< orphan*/ ) ; 
 int strspn (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void check_node_name_chars_strict(struct check *c, struct dt_info *dti,
					 struct node *node)
{
	int n = strspn(node->name, c->data);

	if (n < node->basenamelen)
		FAIL(c, dti, node, "Character '%c' not recommended in node name",
		     node->name[n]);
}