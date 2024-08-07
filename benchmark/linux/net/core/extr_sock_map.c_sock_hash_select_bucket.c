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
typedef  int u32 ;
struct bpf_htab_bucket {int dummy; } ;
struct bpf_htab {int buckets_num; struct bpf_htab_bucket* buckets; } ;

/* Variables and functions */

__attribute__((used)) static struct bpf_htab_bucket *sock_hash_select_bucket(struct bpf_htab *htab,
						       u32 hash)
{
	return &htab->buckets[hash & (htab->buckets_num - 1)];
}