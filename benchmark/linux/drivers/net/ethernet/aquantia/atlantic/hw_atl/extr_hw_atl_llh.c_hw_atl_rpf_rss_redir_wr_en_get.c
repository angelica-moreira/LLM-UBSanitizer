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
struct aq_hw_s {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  HW_ATL_RPF_RSS_REDIR_WR_ENI_ADR ; 
 int /*<<< orphan*/  HW_ATL_RPF_RSS_REDIR_WR_ENI_MSK ; 
 int /*<<< orphan*/  HW_ATL_RPF_RSS_REDIR_WR_ENI_SHIFT ; 
 int /*<<< orphan*/  aq_hw_read_reg_bit (struct aq_hw_s*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

u32 hw_atl_rpf_rss_redir_wr_en_get(struct aq_hw_s *aq_hw)
{
	return aq_hw_read_reg_bit(aq_hw, HW_ATL_RPF_RSS_REDIR_WR_ENI_ADR,
				  HW_ATL_RPF_RSS_REDIR_WR_ENI_MSK,
				  HW_ATL_RPF_RSS_REDIR_WR_ENI_SHIFT);
}