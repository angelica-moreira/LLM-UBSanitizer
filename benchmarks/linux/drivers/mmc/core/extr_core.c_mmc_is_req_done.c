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
struct mmc_request {int /*<<< orphan*/  completion; } ;
struct mmc_host {int dummy; } ;

/* Variables and functions */
 int completion_done (int /*<<< orphan*/ *) ; 

bool mmc_is_req_done(struct mmc_host *host, struct mmc_request *mrq)
{
	return completion_done(&mrq->completion);
}