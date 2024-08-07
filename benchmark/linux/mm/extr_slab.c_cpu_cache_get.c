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
struct kmem_cache {int /*<<< orphan*/  cpu_cache; } ;
struct array_cache {int dummy; } ;

/* Variables and functions */
 struct array_cache* this_cpu_ptr (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct array_cache *cpu_cache_get(struct kmem_cache *cachep)
{
	return this_cpu_ptr(cachep->cpu_cache);
}