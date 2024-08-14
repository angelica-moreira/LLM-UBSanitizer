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
struct bm_rcr {int ci; int /*<<< orphan*/  cursor; int /*<<< orphan*/  busy; } ;
struct bm_portal {struct bm_rcr rcr; } ;

/* Variables and functions */
 int BM_RCR_SIZE ; 
 int /*<<< orphan*/  BM_REG_RCR_CI_CINH ; 
 int /*<<< orphan*/  BM_REG_RCR_PI_CINH ; 
 int /*<<< orphan*/  DPAA_ASSERT (int) ; 
 int bm_in (struct bm_portal*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_crit (char*) ; 
 int rcr_ptr2idx (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void bm_rcr_finish(struct bm_portal *portal)
{
#ifdef CONFIG_FSL_DPAA_CHECKING
	struct bm_rcr *rcr = &portal->rcr;
	int i;

	DPAA_ASSERT(!rcr->busy);

	i = bm_in(portal, BM_REG_RCR_PI_CINH) & (BM_RCR_SIZE - 1);
	if (i != rcr_ptr2idx(rcr->cursor))
		pr_crit("losing uncommitted RCR entries\n");

	i = bm_in(portal, BM_REG_RCR_CI_CINH) & (BM_RCR_SIZE - 1);
	if (i != rcr->ci)
		pr_crit("missing existing RCR completions\n");
	if (rcr->ci != rcr_ptr2idx(rcr->cursor))
		pr_crit("RCR destroyed unquiesced\n");
#endif
}