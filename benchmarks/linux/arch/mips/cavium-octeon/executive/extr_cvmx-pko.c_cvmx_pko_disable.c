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
struct TYPE_2__ {scalar_t__ ena_pko; } ;
union cvmx_pko_reg_flags {int /*<<< orphan*/  u64; TYPE_1__ s; } ;

/* Variables and functions */
 int /*<<< orphan*/  CVMX_PKO_REG_FLAGS ; 
 int /*<<< orphan*/  cvmx_read_csr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cvmx_write_csr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void cvmx_pko_disable(void)
{
	union cvmx_pko_reg_flags pko_reg_flags;
	pko_reg_flags.u64 = cvmx_read_csr(CVMX_PKO_REG_FLAGS);
	pko_reg_flags.s.ena_pko = 0;
	cvmx_write_csr(CVMX_PKO_REG_FLAGS, pko_reg_flags.u64);
}