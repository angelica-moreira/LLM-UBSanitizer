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
struct backref_edge {int dummy; } ;
struct backref_cache {int /*<<< orphan*/  nr_edges; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_NOFS ; 
 struct backref_edge* kzalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct backref_edge *alloc_backref_edge(struct backref_cache *cache)
{
	struct backref_edge *edge;

	edge = kzalloc(sizeof(*edge), GFP_NOFS);
	if (edge)
		cache->nr_edges++;
	return edge;
}