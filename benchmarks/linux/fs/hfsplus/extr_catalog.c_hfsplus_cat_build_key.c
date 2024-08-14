#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_4__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct super_block {int dummy; } ;
struct qstr {int /*<<< orphan*/  len; int /*<<< orphan*/  name; } ;
struct TYPE_7__ {int /*<<< orphan*/  length; } ;
struct TYPE_5__ {TYPE_4__ name; int /*<<< orphan*/  parent; } ;
struct TYPE_6__ {int /*<<< orphan*/  key_len; TYPE_1__ cat; } ;
typedef  TYPE_2__ hfsplus_btree_key ;

/* Variables and functions */
 int /*<<< orphan*/  HFSPLUS_MAX_STRLEN ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be16 (int) ; 
 int /*<<< orphan*/  cpu_to_be32 (int /*<<< orphan*/ ) ; 
 int hfsplus_asc2uni (struct super_block*,TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 

int hfsplus_cat_build_key(struct super_block *sb,
		hfsplus_btree_key *key, u32 parent, const struct qstr *str)
{
	int len, err;

	key->cat.parent = cpu_to_be32(parent);
	err = hfsplus_asc2uni(sb, &key->cat.name, HFSPLUS_MAX_STRLEN,
			str->name, str->len);
	if (unlikely(err < 0))
		return err;

	len = be16_to_cpu(key->cat.name.length);
	key->key_len = cpu_to_be16(6 + 2 * len);
	return 0;
}