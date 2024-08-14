#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct neighbour {TYPE_1__* ops; int /*<<< orphan*/  output; } ;
struct TYPE_2__ {int /*<<< orphan*/  output; } ;

/* Variables and functions */
 int /*<<< orphan*/  neigh_dbg (int,char*,struct neighbour*) ; 

__attribute__((used)) static void neigh_suspect(struct neighbour *neigh)
{
	neigh_dbg(2, "neigh %p is suspected\n", neigh);

	neigh->output = neigh->ops->output;
}