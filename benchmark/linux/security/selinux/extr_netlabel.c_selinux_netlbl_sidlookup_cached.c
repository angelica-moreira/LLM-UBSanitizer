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
typedef  int /*<<< orphan*/  u16 ;
struct sk_buff {int dummy; } ;
struct netlbl_lsm_secattr {int flags; } ;

/* Variables and functions */
 int NETLBL_SECATTR_CACHE ; 
 int NETLBL_SECATTR_CACHEABLE ; 
 int /*<<< orphan*/  netlbl_cache_add (struct sk_buff*,int /*<<< orphan*/ ,struct netlbl_lsm_secattr*) ; 
 int security_netlbl_secattr_to_sid (int /*<<< orphan*/ *,struct netlbl_lsm_secattr*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  selinux_state ; 

__attribute__((used)) static int selinux_netlbl_sidlookup_cached(struct sk_buff *skb,
					   u16 family,
					   struct netlbl_lsm_secattr *secattr,
					   u32 *sid)
{
	int rc;

	rc = security_netlbl_secattr_to_sid(&selinux_state, secattr, sid);
	if (rc == 0 &&
	    (secattr->flags & NETLBL_SECATTR_CACHEABLE) &&
	    (secattr->flags & NETLBL_SECATTR_CACHE))
		netlbl_cache_add(skb, family, secattr);

	return rc;
}