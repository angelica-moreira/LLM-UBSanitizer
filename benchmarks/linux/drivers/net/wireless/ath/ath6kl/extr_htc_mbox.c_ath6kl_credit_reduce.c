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
struct htc_endpoint_credit_dist {int cred_assngd; int credits; int /*<<< orphan*/  endpoint; } ;
struct ath6kl_htc_credit_info {int cur_free_credits; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATH6KL_DBG_CREDIT ; 
 int /*<<< orphan*/  ath6kl_dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void ath6kl_credit_reduce(struct ath6kl_htc_credit_info *cred_info,
				 struct htc_endpoint_credit_dist *ep_dist,
				 int limit)
{
	int credits;

	ath6kl_dbg(ATH6KL_DBG_CREDIT, "credit reduce ep %d limit %d\n",
		   ep_dist->endpoint, limit);

	ep_dist->cred_assngd = limit;

	if (ep_dist->credits <= limit)
		return;

	credits = ep_dist->credits - limit;
	ep_dist->credits -= credits;
	cred_info->cur_free_credits += credits;
}