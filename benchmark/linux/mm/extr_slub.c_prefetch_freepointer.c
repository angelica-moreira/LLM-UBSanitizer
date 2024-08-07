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
struct kmem_cache {int offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  prefetch (void*) ; 

__attribute__((used)) static void prefetch_freepointer(const struct kmem_cache *s, void *object)
{
	prefetch(object + s->offset);
}