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
struct hwrm_func_reset_input {scalar_t__ enables; int /*<<< orphan*/  member_0; } ;
struct bnxt {int dummy; } ;
typedef  int /*<<< orphan*/  req ;

/* Variables and functions */
 int /*<<< orphan*/  HWRM_FUNC_RESET ; 
 int /*<<< orphan*/  HWRM_RESET_TIMEOUT ; 
 int /*<<< orphan*/  bnxt_hwrm_cmd_hdr_init (struct bnxt*,struct hwrm_func_reset_input*,int /*<<< orphan*/ ,int,int) ; 
 int hwrm_send_message (struct bnxt*,struct hwrm_func_reset_input*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int bnxt_hwrm_func_reset(struct bnxt *bp)
{
	struct hwrm_func_reset_input req = {0};

	bnxt_hwrm_cmd_hdr_init(bp, &req, HWRM_FUNC_RESET, -1, -1);
	req.enables = 0;

	return hwrm_send_message(bp, &req, sizeof(req), HWRM_RESET_TIMEOUT);
}