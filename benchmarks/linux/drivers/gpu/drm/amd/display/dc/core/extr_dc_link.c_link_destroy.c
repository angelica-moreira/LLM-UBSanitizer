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
struct dc_link {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  destruct (struct dc_link*) ; 
 int /*<<< orphan*/  kfree (struct dc_link*) ; 

void link_destroy(struct dc_link **link)
{
	destruct(*link);
	kfree(*link);
	*link = NULL;
}