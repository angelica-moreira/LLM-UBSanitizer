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
struct closure {int /*<<< orphan*/  remaining; struct closure* parent; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLOSURE_REMAINING_INITIALIZER ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  closure_debug_create (struct closure*) ; 
 int /*<<< orphan*/  closure_get (struct closure*) ; 
 int /*<<< orphan*/  closure_set_ip (struct closure*) ; 
 int /*<<< orphan*/  memset (struct closure*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void closure_init(struct closure *cl, struct closure *parent)
{
	memset(cl, 0, sizeof(struct closure));
	cl->parent = parent;
	if (parent)
		closure_get(parent);

	atomic_set(&cl->remaining, CLOSURE_REMAINING_INITIALIZER);

	closure_debug_create(cl);
	closure_set_ip(cl);
}