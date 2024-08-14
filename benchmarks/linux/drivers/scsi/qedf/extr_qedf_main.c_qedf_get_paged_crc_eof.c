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
struct sk_buff {int dummy; } ;

/* Variables and functions */
 int fcoe_get_paged_crc_eof (struct sk_buff*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  qedf_global ; 
 int /*<<< orphan*/  qedf_global_lock ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int qedf_get_paged_crc_eof(struct sk_buff *skb, int tlen)
{
	int rc;

	spin_lock(&qedf_global_lock);
	rc = fcoe_get_paged_crc_eof(skb, tlen, &qedf_global);
	spin_unlock(&qedf_global_lock);

	return rc;
}