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
struct smack_known {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  current_cred () ; 
 int /*<<< orphan*/  smack_cred (int /*<<< orphan*/ ) ; 
 struct smack_known* smk_of_task (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct smack_known *smk_of_current(void)
{
	return smk_of_task(smack_cred(current_cred()));
}