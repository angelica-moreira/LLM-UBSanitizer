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
struct smack_known {int /*<<< orphan*/  smk_secid; } ;

/* Variables and functions */
 struct smack_known* smk_find_entry (char const*) ; 

__attribute__((used)) static int smack_secctx_to_secid(const char *secdata, u32 seclen, u32 *secid)
{
	struct smack_known *skp = smk_find_entry(secdata);

	if (skp)
		*secid = skp->smk_secid;
	else
		*secid = 0;
	return 0;
}