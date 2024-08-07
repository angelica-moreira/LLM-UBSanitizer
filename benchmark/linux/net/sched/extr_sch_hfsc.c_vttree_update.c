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
struct hfsc_class {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  vttree_insert (struct hfsc_class*) ; 
 int /*<<< orphan*/  vttree_remove (struct hfsc_class*) ; 

__attribute__((used)) static inline void
vttree_update(struct hfsc_class *cl)
{
	vttree_remove(cl);
	vttree_insert(cl);
}