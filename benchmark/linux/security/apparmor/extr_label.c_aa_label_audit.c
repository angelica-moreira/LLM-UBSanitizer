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
struct audit_buffer {int dummy; } ;
struct aa_ns {int dummy; } ;
struct aa_label {int dummy; } ;
typedef  int /*<<< orphan*/  gfp_t ;

/* Variables and functions */
 int /*<<< orphan*/  FLAG_VIEW_SUBNS ; 
 struct aa_ns* aa_get_current_ns () ; 
 int /*<<< orphan*/  aa_label_xaudit (struct audit_buffer*,struct aa_ns*,struct aa_label*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  aa_put_ns (struct aa_ns*) ; 

void aa_label_audit(struct audit_buffer *ab, struct aa_label *label, gfp_t gfp)
{
	struct aa_ns *ns = aa_get_current_ns();

	aa_label_xaudit(ab, ns, label, FLAG_VIEW_SUBNS, gfp);
	aa_put_ns(ns);
}