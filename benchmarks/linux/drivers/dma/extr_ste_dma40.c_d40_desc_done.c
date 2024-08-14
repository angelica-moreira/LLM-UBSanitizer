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
struct d40_desc {int /*<<< orphan*/  node; } ;
struct d40_chan {int /*<<< orphan*/  done; } ;

/* Variables and functions */
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void d40_desc_done(struct d40_chan *d40c, struct d40_desc *desc)
{
	list_add_tail(&desc->node, &d40c->done);
}