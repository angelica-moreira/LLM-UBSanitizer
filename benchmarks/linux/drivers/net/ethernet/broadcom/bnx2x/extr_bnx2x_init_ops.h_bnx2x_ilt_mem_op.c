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
typedef  int /*<<< orphan*/  u8 ;
struct bnx2x {int dummy; } ;

/* Variables and functions */
 scalar_t__ CNIC_SUPPORT (struct bnx2x*) ; 
 int /*<<< orphan*/  CONFIGURE_NIC_MODE (struct bnx2x*) ; 
 int /*<<< orphan*/  ILT_CLIENT_CDU ; 
 int /*<<< orphan*/  ILT_CLIENT_QM ; 
 int /*<<< orphan*/  ILT_CLIENT_SRC ; 
 int bnx2x_ilt_client_mem_op (struct bnx2x*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int bnx2x_ilt_mem_op(struct bnx2x *bp, u8 memop)
{
	int rc = bnx2x_ilt_client_mem_op(bp, ILT_CLIENT_CDU, memop);
	if (!rc)
		rc = bnx2x_ilt_client_mem_op(bp, ILT_CLIENT_QM, memop);
	if (!rc && CNIC_SUPPORT(bp) && !CONFIGURE_NIC_MODE(bp))
		rc = bnx2x_ilt_client_mem_op(bp, ILT_CLIENT_SRC, memop);

	return rc;
}