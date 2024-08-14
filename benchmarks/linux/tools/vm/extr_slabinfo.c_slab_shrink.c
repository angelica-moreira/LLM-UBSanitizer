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
struct slabinfo {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  set_obj (struct slabinfo*,char*,int) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void slab_shrink(struct slabinfo *s)
{
	if (strcmp(s->name, "*") == 0)
		return;

	set_obj(s, "shrink", 1);
}