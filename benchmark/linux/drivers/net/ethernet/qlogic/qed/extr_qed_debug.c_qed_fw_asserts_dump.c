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
typedef  size_t u8 ;
typedef  int u32 ;
struct storm_defs {size_t block_id; char letter; int sem_fast_mem_addr; } ;
struct qed_ptt {int dummy; } ;
struct dbg_tools_data {scalar_t__* block_in_reset; } ;
struct qed_hwfn {struct dbg_tools_data dbg_info; } ;
struct fw_asserts_ram_section {int list_element_dword_size; int list_num_elements; int list_dword_offset; int /*<<< orphan*/  list_next_index_dword_offset; int /*<<< orphan*/  section_ram_line_offset; } ;
struct fw_info {struct fw_asserts_ram_section fw_asserts_section; } ;

/* Variables and functions */
 int BYTES_TO_DWORDS (int) ; 
 int DWORDS_TO_BYTES (int /*<<< orphan*/ ) ; 
 size_t MAX_DBG_STORMS ; 
 int RAM_LINES_TO_BYTES (int /*<<< orphan*/ ) ; 
 int SEM_FAST_REG_INT_RAM ; 
 int /*<<< orphan*/  SPLIT_TYPE_NONE ; 
 int qed_dump_common_global_params (struct qed_hwfn*,struct qed_ptt*,int*,int,int) ; 
 int qed_dump_last_section (int*,int,int) ; 
 int qed_dump_num_param (int*,int,char*,int) ; 
 int qed_dump_section_hdr (int*,int,char*,int) ; 
 int qed_dump_str_param (int*,int,char*,char*) ; 
 int qed_grc_dump_addr_range (struct qed_hwfn*,struct qed_ptt*,int*,int,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int qed_rd (struct qed_hwfn*,struct qed_ptt*,int) ; 
 int /*<<< orphan*/  qed_read_storm_fw_info (struct qed_hwfn*,struct qed_ptt*,size_t,struct fw_info*) ; 
 struct storm_defs* s_storm_defs ; 

__attribute__((used)) static u32 qed_fw_asserts_dump(struct qed_hwfn *p_hwfn,
			       struct qed_ptt *p_ptt, u32 *dump_buf, bool dump)
{
	struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
	struct fw_asserts_ram_section *asserts;
	char storm_letter_str[2] = "?";
	struct fw_info fw_info;
	u32 offset = 0;
	u8 storm_id;

	/* Dump global params */
	offset += qed_dump_common_global_params(p_hwfn,
						p_ptt,
						dump_buf + offset, dump, 1);
	offset += qed_dump_str_param(dump_buf + offset,
				     dump, "dump-type", "fw-asserts");

	/* Find Storm dump size */
	for (storm_id = 0; storm_id < MAX_DBG_STORMS; storm_id++) {
		u32 fw_asserts_section_addr, next_list_idx_addr, next_list_idx;
		struct storm_defs *storm = &s_storm_defs[storm_id];
		u32 last_list_idx, addr;

		if (dev_data->block_in_reset[storm->block_id])
			continue;

		/* Read FW info for the current Storm */
		qed_read_storm_fw_info(p_hwfn, p_ptt, storm_id, &fw_info);

		asserts = &fw_info.fw_asserts_section;

		/* Dump FW Asserts section header and params */
		storm_letter_str[0] = storm->letter;
		offset += qed_dump_section_hdr(dump_buf + offset,
					       dump, "fw_asserts", 2);
		offset += qed_dump_str_param(dump_buf + offset,
					     dump, "storm", storm_letter_str);
		offset += qed_dump_num_param(dump_buf + offset,
					     dump,
					     "size",
					     asserts->list_element_dword_size);

		/* Read and dump FW Asserts data */
		if (!dump) {
			offset += asserts->list_element_dword_size;
			continue;
		}

		fw_asserts_section_addr = storm->sem_fast_mem_addr +
			SEM_FAST_REG_INT_RAM +
			RAM_LINES_TO_BYTES(asserts->section_ram_line_offset);
		next_list_idx_addr = fw_asserts_section_addr +
			DWORDS_TO_BYTES(asserts->list_next_index_dword_offset);
		next_list_idx = qed_rd(p_hwfn, p_ptt, next_list_idx_addr);
		last_list_idx = (next_list_idx > 0 ?
				 next_list_idx :
				 asserts->list_num_elements) - 1;
		addr = BYTES_TO_DWORDS(fw_asserts_section_addr) +
		       asserts->list_dword_offset +
		       last_list_idx * asserts->list_element_dword_size;
		offset +=
		    qed_grc_dump_addr_range(p_hwfn, p_ptt,
					    dump_buf + offset,
					    dump, addr,
					    asserts->list_element_dword_size,
						  false, SPLIT_TYPE_NONE, 0);
	}

	/* Dump last section */
	offset += qed_dump_last_section(dump_buf, offset, dump);

	return offset;
}