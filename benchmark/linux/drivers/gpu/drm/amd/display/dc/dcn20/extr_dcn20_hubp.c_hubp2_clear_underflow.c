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
struct hubp {int dummy; } ;
struct dcn20_hubp {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DCHUBP_CNTL ; 
 int /*<<< orphan*/  HUBP_UNDERFLOW_CLEAR ; 
 int /*<<< orphan*/  REG_UPDATE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct dcn20_hubp* TO_DCN20_HUBP (struct hubp*) ; 

void hubp2_clear_underflow(struct hubp *hubp)
{
	struct dcn20_hubp *hubp2 = TO_DCN20_HUBP(hubp);

	REG_UPDATE(DCHUBP_CNTL, HUBP_UNDERFLOW_CLEAR, 1);
}