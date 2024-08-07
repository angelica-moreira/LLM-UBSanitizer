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
struct bpf_sk_storage_elem {int /*<<< orphan*/  map_node; } ;

/* Variables and functions */
 int /*<<< orphan*/  hlist_unhashed (int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool selem_linked_to_map(const struct bpf_sk_storage_elem *selem)
{
	return !hlist_unhashed(&selem->map_node);
}