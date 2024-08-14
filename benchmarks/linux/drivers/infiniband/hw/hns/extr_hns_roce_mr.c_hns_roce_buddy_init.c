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
struct hns_roce_buddy {int max_order; int* bits; int* num_free; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int BITS_TO_LONGS (int) ; 
 int ENOMEM ; 
 int GFP_KERNEL ; 
 int __GFP_NOWARN ; 
 int /*<<< orphan*/  array_size (int,int) ; 
 void* kcalloc (int,int,int) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int /*<<< orphan*/  kvfree (int) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int vzalloc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int hns_roce_buddy_init(struct hns_roce_buddy *buddy, int max_order)
{
	int i, s;

	buddy->max_order = max_order;
	spin_lock_init(&buddy->lock);
	buddy->bits = kcalloc(buddy->max_order + 1,
			      sizeof(*buddy->bits),
			      GFP_KERNEL);
	buddy->num_free = kcalloc(buddy->max_order + 1,
				  sizeof(*buddy->num_free),
				  GFP_KERNEL);
	if (!buddy->bits || !buddy->num_free)
		goto err_out;

	for (i = 0; i <= buddy->max_order; ++i) {
		s = BITS_TO_LONGS(1 << (buddy->max_order - i));
		buddy->bits[i] = kcalloc(s, sizeof(long), GFP_KERNEL |
					 __GFP_NOWARN);
		if (!buddy->bits[i]) {
			buddy->bits[i] = vzalloc(array_size(s, sizeof(long)));
			if (!buddy->bits[i])
				goto err_out_free;
		}
	}

	set_bit(0, buddy->bits[buddy->max_order]);
	buddy->num_free[buddy->max_order] = 1;

	return 0;

err_out_free:
	for (i = 0; i <= buddy->max_order; ++i)
		kvfree(buddy->bits[i]);

err_out:
	kfree(buddy->bits);
	kfree(buddy->num_free);
	return -ENOMEM;
}