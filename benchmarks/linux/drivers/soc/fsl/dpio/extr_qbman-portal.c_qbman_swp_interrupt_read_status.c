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
struct qbman_swp {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  QBMAN_CINH_SWP_ISR ; 
 int /*<<< orphan*/  qbman_read_register (struct qbman_swp*,int /*<<< orphan*/ ) ; 

u32 qbman_swp_interrupt_read_status(struct qbman_swp *p)
{
	return qbman_read_register(p, QBMAN_CINH_SWP_ISR);
}