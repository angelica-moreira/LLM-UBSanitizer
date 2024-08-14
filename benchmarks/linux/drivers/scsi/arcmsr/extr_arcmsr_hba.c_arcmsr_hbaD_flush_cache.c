#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct MessageUnit_D {int /*<<< orphan*/  inbound_msgaddr0; } ;
struct AdapterControlBlock {TYPE_1__* host; struct MessageUnit_D* pmuD; } ;
struct TYPE_2__ {int /*<<< orphan*/  host_no; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARCMSR_INBOUND_MESG0_FLUSH_CACHE ; 
 scalar_t__ arcmsr_hbaD_wait_msgint_ready (struct AdapterControlBlock*) ; 
 int /*<<< orphan*/  pr_notice (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void arcmsr_hbaD_flush_cache(struct AdapterControlBlock *pACB)
{
	int retry_count = 15;
	struct MessageUnit_D *reg = pACB->pmuD;

	writel(ARCMSR_INBOUND_MESG0_FLUSH_CACHE, reg->inbound_msgaddr0);
	do {
		if (arcmsr_hbaD_wait_msgint_ready(pACB))
			break;

		retry_count--;
		pr_notice("arcmsr%d: wait 'flush adapter "
			"cache' timeout, retry count down = %d\n",
			pACB->host->host_no, retry_count);
	} while (retry_count != 0);
}