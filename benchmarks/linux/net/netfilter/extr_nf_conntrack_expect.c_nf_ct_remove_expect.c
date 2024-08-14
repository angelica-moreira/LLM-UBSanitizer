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
struct nf_conntrack_expect {int /*<<< orphan*/  timeout; } ;

/* Variables and functions */
 scalar_t__ del_timer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nf_ct_expect_put (struct nf_conntrack_expect*) ; 
 int /*<<< orphan*/  nf_ct_unlink_expect (struct nf_conntrack_expect*) ; 

bool nf_ct_remove_expect(struct nf_conntrack_expect *exp)
{
	if (del_timer(&exp->timeout)) {
		nf_ct_unlink_expect(exp);
		nf_ct_expect_put(exp);
		return true;
	}
	return false;
}