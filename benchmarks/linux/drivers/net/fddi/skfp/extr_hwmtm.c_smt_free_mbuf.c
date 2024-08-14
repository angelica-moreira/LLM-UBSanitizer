#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {TYPE_4__* mb_free; } ;
struct TYPE_10__ {TYPE_2__ mbuf_pool; } ;
struct TYPE_8__ {TYPE_3__ hwm; } ;
struct s_smc {TYPE_1__ os; } ;
struct TYPE_11__ {struct TYPE_11__* sm_next; struct TYPE_11__* sm_use_count; } ;
typedef  TYPE_4__ SMbuf ;

/* Variables and functions */
 int /*<<< orphan*/  DB_GEN (int,char*,TYPE_4__*) ; 
 int /*<<< orphan*/  HWM_E0003 ; 
 int /*<<< orphan*/  HWM_E0003_MSG ; 
 int /*<<< orphan*/  SMT_PANIC (struct s_smc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_4__* mb_free ; 

void smt_free_mbuf(struct s_smc *smc, SMbuf *mb)
{

	if (mb) {
		mb->sm_use_count-- ;
		DB_GEN(3, "free_mbuf: sm_use_count = %d", mb->sm_use_count);
		/*
		 * If the use_count is != zero the MBuf is queued
		 * more than once and must not queued into the
		 * free MBuf queue
		 */
		if (!mb->sm_use_count) {
			DB_GEN(3, "free SMbuf: mb = %p", mb);
#ifndef	COMMON_MB_POOL
			mb->sm_next = smc->os.hwm.mbuf_pool.mb_free ;
			smc->os.hwm.mbuf_pool.mb_free = mb ;
#else
			mb->sm_next = mb_free ;
			mb_free = mb ;
#endif
		}
	}
	else
		SMT_PANIC(smc,HWM_E0003,HWM_E0003_MSG) ;
}