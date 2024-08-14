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
typedef  int /*<<< orphan*/  u32 ;
struct task_security_struct {int /*<<< orphan*/  sid; } ;
struct cred {int dummy; } ;

/* Variables and functions */
 struct task_security_struct* selinux_cred (struct cred const*) ; 

__attribute__((used)) static inline u32 cred_sid(const struct cred *cred)
{
	const struct task_security_struct *tsec;

	tsec = selinux_cred(cred);
	return tsec->sid;
}