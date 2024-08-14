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
typedef  scalar_t__ u8 ;
struct btf_type {int /*<<< orphan*/  info; } ;

/* Variables and functions */
 scalar_t__ BTF_INFO_KIND (int /*<<< orphan*/ ) ; 
 scalar_t__ BTF_KIND_STRUCT ; 
 scalar_t__ BTF_KIND_UNION ; 

__attribute__((used)) static bool btf_type_is_struct(const struct btf_type *t)
{
	u8 kind = BTF_INFO_KIND(t->info);

	return kind == BTF_KIND_STRUCT || kind == BTF_KIND_UNION;
}