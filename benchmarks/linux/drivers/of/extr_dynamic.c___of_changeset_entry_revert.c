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
struct of_changeset_entry {int dummy; } ;

/* Variables and functions */
 int __of_changeset_entry_apply (struct of_changeset_entry*) ; 
 int /*<<< orphan*/  __of_changeset_entry_invert (struct of_changeset_entry*,struct of_changeset_entry*) ; 

__attribute__((used)) static inline int __of_changeset_entry_revert(struct of_changeset_entry *ce)
{
	struct of_changeset_entry ce_inverted;

	__of_changeset_entry_invert(ce, &ce_inverted);
	return __of_changeset_entry_apply(&ce_inverted);
}