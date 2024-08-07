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
struct chtls_sock {int /*<<< orphan*/  flags; } ;
typedef  enum csk_flags { ____Placeholder_csk_flags } csk_flags ;

/* Variables and functions */
 int test_bit (int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int csk_flag_nochk(const struct chtls_sock *csk,
				 enum csk_flags flag)
{
	return test_bit(flag, &csk->flags);
}