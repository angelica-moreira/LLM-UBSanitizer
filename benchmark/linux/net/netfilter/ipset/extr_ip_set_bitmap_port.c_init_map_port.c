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
typedef  void* u16 ;
struct ip_set {int /*<<< orphan*/  family; struct bitmap_port* data; int /*<<< orphan*/  timeout; } ;
struct bitmap_port {struct ip_set* set; void* last_port; void* first_port; int /*<<< orphan*/  members; int /*<<< orphan*/  memsize; } ;

/* Variables and functions */
 int /*<<< orphan*/  IPSET_NO_TIMEOUT ; 
 int /*<<< orphan*/  NFPROTO_UNSPEC ; 
 int /*<<< orphan*/  ip_set_alloc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool
init_map_port(struct ip_set *set, struct bitmap_port *map,
	      u16 first_port, u16 last_port)
{
	map->members = ip_set_alloc(map->memsize);
	if (!map->members)
		return false;
	map->first_port = first_port;
	map->last_port = last_port;
	set->timeout = IPSET_NO_TIMEOUT;

	map->set = set;
	set->data = map;
	set->family = NFPROTO_UNSPEC;

	return true;
}