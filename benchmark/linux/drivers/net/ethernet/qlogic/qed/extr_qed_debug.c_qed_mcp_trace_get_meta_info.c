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
typedef  int u32 ;
struct qed_ptt {int dummy; } ;
struct qed_hwfn {int dummy; } ;
typedef  enum dbg_status { ____Placeholder_dbg_status } dbg_status ;

/* Variables and functions */
 int DBG_STATUS_INVALID_NVRAM_BUNDLE ; 
 int DIR_ID_1 ; 
 int MCP_REG_SCRATCH ; 
 int MCP_SPAD_TRACE_OFFSIZE_ADDR ; 
 int NVM_TYPE_MFW_TRACE1 ; 
 int NVM_TYPE_MFW_TRACE2 ; 
 int QED_SECTION_SIZE (int) ; 
 int SECTION_OFFSET (int) ; 
 int qed_find_nvram_image (struct qed_hwfn*,struct qed_ptt*,int,int*,int*) ; 
 int qed_rd (struct qed_hwfn*,struct qed_ptt*,int) ; 

__attribute__((used)) static enum dbg_status qed_mcp_trace_get_meta_info(struct qed_hwfn *p_hwfn,
						   struct qed_ptt *p_ptt,
						   u32 trace_data_size_bytes,
						   u32 *running_bundle_id,
						   u32 *trace_meta_offset,
						   u32 *trace_meta_size)
{
	u32 spad_trace_offsize, nvram_image_type, running_mfw_addr;

	/* Read MCP trace section offsize structure from MCP scratchpad */
	spad_trace_offsize = qed_rd(p_hwfn, p_ptt, MCP_SPAD_TRACE_OFFSIZE_ADDR);

	/* Find running bundle ID */
	running_mfw_addr =
		MCP_REG_SCRATCH + SECTION_OFFSET(spad_trace_offsize) +
		QED_SECTION_SIZE(spad_trace_offsize) + trace_data_size_bytes;
	*running_bundle_id = qed_rd(p_hwfn, p_ptt, running_mfw_addr);
	if (*running_bundle_id > 1)
		return DBG_STATUS_INVALID_NVRAM_BUNDLE;

	/* Find image in NVRAM */
	nvram_image_type =
	    (*running_bundle_id ==
	     DIR_ID_1) ? NVM_TYPE_MFW_TRACE1 : NVM_TYPE_MFW_TRACE2;
	return qed_find_nvram_image(p_hwfn,
				    p_ptt,
				    nvram_image_type,
				    trace_meta_offset, trace_meta_size);
}