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
struct btf_type {int dummy; } ;
struct btf_enum {scalar_t__ name_off; scalar_t__ val; } ;
typedef  int __u16 ;

/* Variables and functions */
 struct btf_enum* btf_enum (struct btf_type*) ; 
 int /*<<< orphan*/  btf_equal_common (struct btf_type*,struct btf_type*) ; 
 int btf_vlen (struct btf_type*) ; 

__attribute__((used)) static bool btf_equal_enum(struct btf_type *t1, struct btf_type *t2)
{
	const struct btf_enum *m1, *m2;
	__u16 vlen;
	int i;

	if (!btf_equal_common(t1, t2))
		return false;

	vlen = btf_vlen(t1);
	m1 = btf_enum(t1);
	m2 = btf_enum(t2);
	for (i = 0; i < vlen; i++) {
		if (m1->name_off != m2->name_off || m1->val != m2->val)
			return false;
		m1++;
		m2++;
	}
	return true;
}