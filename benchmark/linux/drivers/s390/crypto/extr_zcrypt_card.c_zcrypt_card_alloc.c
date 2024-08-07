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
struct zcrypt_card {int /*<<< orphan*/  refcount; int /*<<< orphan*/  zqueues; int /*<<< orphan*/  list; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_init (int /*<<< orphan*/ *) ; 
 struct zcrypt_card* kzalloc (int,int /*<<< orphan*/ ) ; 

struct zcrypt_card *zcrypt_card_alloc(void)
{
	struct zcrypt_card *zc;

	zc = kzalloc(sizeof(struct zcrypt_card), GFP_KERNEL);
	if (!zc)
		return NULL;
	INIT_LIST_HEAD(&zc->list);
	INIT_LIST_HEAD(&zc->zqueues);
	kref_init(&zc->refcount);
	return zc;
}