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
struct btree_keys {int /*<<< orphan*/  set; } ;
struct btree_iter {int dummy; } ;
struct bkey {int dummy; } ;

/* Variables and functions */
 struct bkey* __bch_btree_iter_init (struct btree_keys*,struct btree_iter*,struct bkey*,int /*<<< orphan*/ ) ; 

struct bkey *bch_btree_iter_init(struct btree_keys *b,
				 struct btree_iter *iter,
				 struct bkey *search)
{
	return __bch_btree_iter_init(b, iter, search, b->set);
}