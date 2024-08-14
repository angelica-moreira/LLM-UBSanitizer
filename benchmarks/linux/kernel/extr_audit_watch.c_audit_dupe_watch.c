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
struct audit_watch {int /*<<< orphan*/  parent; int /*<<< orphan*/  ino; int /*<<< orphan*/  dev; int /*<<< orphan*/  path; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENOMEM ; 
 struct audit_watch* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct audit_watch*) ; 
 int /*<<< orphan*/  audit_get_parent (int /*<<< orphan*/ ) ; 
 struct audit_watch* audit_init_watch (char*) ; 
 int /*<<< orphan*/  kfree (char*) ; 
 char* kstrdup (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static struct audit_watch *audit_dupe_watch(struct audit_watch *old)
{
	char *path;
	struct audit_watch *new;

	path = kstrdup(old->path, GFP_KERNEL);
	if (unlikely(!path))
		return ERR_PTR(-ENOMEM);

	new = audit_init_watch(path);
	if (IS_ERR(new)) {
		kfree(path);
		goto out;
	}

	new->dev = old->dev;
	new->ino = old->ino;
	audit_get_parent(old->parent);
	new->parent = old->parent;

out:
	return new;
}