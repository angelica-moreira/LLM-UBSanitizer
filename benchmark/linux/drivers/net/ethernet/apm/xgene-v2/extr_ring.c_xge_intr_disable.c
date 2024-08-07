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
struct xge_pdata {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMAINTRMASK ; 
 int /*<<< orphan*/  xge_wr_csr (struct xge_pdata*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void xge_intr_disable(struct xge_pdata *pdata)
{
	xge_wr_csr(pdata, DMAINTRMASK, 0);
}