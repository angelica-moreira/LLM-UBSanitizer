#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_3__* txd_tx_pipe; int /*<<< orphan*/  queued_txd_mb; } ;
struct TYPE_7__ {TYPE_1__ hwm; } ;
struct s_smc {TYPE_2__ os; } ;
struct TYPE_8__ {struct TYPE_8__* sm_next; } ;
typedef  TYPE_3__ SMbuf ;

/* Variables and functions */
 int /*<<< orphan*/  DB_GEN (int,char*,TYPE_3__*) ; 

__attribute__((used)) static SMbuf *get_txd_mb(struct s_smc *smc)
{
	SMbuf *mb ;

	if ((mb = smc->os.hwm.txd_tx_pipe)) {
		smc->os.hwm.queued_txd_mb-- ;
		smc->os.hwm.txd_tx_pipe = mb->sm_next ;
	}
	DB_GEN(4, "get_txd_mb: mb = 0x%p", mb);
	return mb;
}