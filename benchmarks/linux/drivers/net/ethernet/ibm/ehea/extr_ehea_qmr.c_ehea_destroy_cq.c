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
typedef  scalar_t__ u64 ;
struct ehea_cq {int /*<<< orphan*/  fw_handle; int /*<<< orphan*/  adapter; int /*<<< orphan*/  epas; } ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  FORCE_FREE ; 
 scalar_t__ H_R_STATE ; 
 scalar_t__ H_SUCCESS ; 
 int /*<<< orphan*/  NORMAL_FREE ; 
 scalar_t__ ehea_destroy_cq_res (struct ehea_cq*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ehea_error_data (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*,scalar_t__*) ; 
 int /*<<< orphan*/  hcp_epas_dtor (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*) ; 

int ehea_destroy_cq(struct ehea_cq *cq)
{
	u64 hret, aer, aerr;
	if (!cq)
		return 0;

	hcp_epas_dtor(&cq->epas);
	hret = ehea_destroy_cq_res(cq, NORMAL_FREE);
	if (hret == H_R_STATE) {
		ehea_error_data(cq->adapter, cq->fw_handle, &aer, &aerr);
		hret = ehea_destroy_cq_res(cq, FORCE_FREE);
	}

	if (hret != H_SUCCESS) {
		pr_err("destroy CQ failed\n");
		return -EIO;
	}

	return 0;
}