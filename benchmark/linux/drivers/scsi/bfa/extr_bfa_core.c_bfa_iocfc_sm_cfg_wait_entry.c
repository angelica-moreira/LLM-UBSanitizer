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
struct bfa_iocfc_s {int /*<<< orphan*/  bfa; } ;

/* Variables and functions */
 int /*<<< orphan*/  bfa_iocfc_send_cfg (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
bfa_iocfc_sm_cfg_wait_entry(struct bfa_iocfc_s *iocfc)
{
	bfa_iocfc_send_cfg(iocfc->bfa);
}