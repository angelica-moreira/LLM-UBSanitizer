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
struct auxtrace_cache {int /*<<< orphan*/  entry_size; } ;

/* Variables and functions */
 void* malloc (int /*<<< orphan*/ ) ; 

void *auxtrace_cache__alloc_entry(struct auxtrace_cache *c)
{
	return malloc(c->entry_size);
}