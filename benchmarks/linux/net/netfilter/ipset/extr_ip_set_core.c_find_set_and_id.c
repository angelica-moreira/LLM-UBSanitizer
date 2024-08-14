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
struct ip_set_net {scalar_t__ ip_set_max; } ;
struct ip_set {int /*<<< orphan*/  name; } ;
typedef  scalar_t__ ip_set_id_t ;

/* Variables and functions */
 scalar_t__ IPSET_INVALID_ID ; 
 scalar_t__ STRNCMP (int /*<<< orphan*/ ,char const*) ; 
 struct ip_set* ip_set (struct ip_set_net*,scalar_t__) ; 

__attribute__((used)) static struct ip_set *
find_set_and_id(struct ip_set_net *inst, const char *name, ip_set_id_t *id)
{
	struct ip_set *set = NULL;
	ip_set_id_t i;

	*id = IPSET_INVALID_ID;
	for (i = 0; i < inst->ip_set_max; i++) {
		set = ip_set(inst, i);
		if (set && STRNCMP(set->name, name)) {
			*id = i;
			break;
		}
	}
	return (*id == IPSET_INVALID_ID ? NULL : set);
}