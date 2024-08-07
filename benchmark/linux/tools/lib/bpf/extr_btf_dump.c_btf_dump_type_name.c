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
struct btf_dump {int /*<<< orphan*/  type_names; } ;
typedef  int /*<<< orphan*/  __u32 ;

/* Variables and functions */
 char const* btf_dump_resolve_name (struct btf_dump*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static const char *btf_dump_type_name(struct btf_dump *d, __u32 id)
{
	return btf_dump_resolve_name(d, id, d->type_names);
}