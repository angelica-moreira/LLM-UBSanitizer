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
typedef  int /*<<< orphan*/  uint32_t ;
struct nlattr {int dummy; } ;

/* Variables and functions */
 scalar_t__ libbpf_nla_data (struct nlattr const*) ; 

__attribute__((used)) static inline uint32_t libbpf_nla_getattr_u32(const struct nlattr *nla)
{
	return *(uint32_t *)libbpf_nla_data(nla);
}