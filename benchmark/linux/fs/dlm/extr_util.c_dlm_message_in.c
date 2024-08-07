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
struct dlm_message {void* m_result; void* m_asts; void* m_bastmode; void* m_rqmode; void* m_grmode; void* m_status; void* m_hash; void* m_lvbseq; void* m_flags; void* m_sbflags; void* m_exflags; void* m_parent_remid; void* m_parent_lkid; void* m_remid; void* m_lkid; void* m_pid; void* m_nodeid; void* m_type; int /*<<< orphan*/  m_header; } ;

/* Variables and functions */
 void* from_dlm_errno (void*) ; 
 int /*<<< orphan*/  header_in (int /*<<< orphan*/ *) ; 
 void* le32_to_cpu (void*) ; 

void dlm_message_in(struct dlm_message *ms)
{
	header_in(&ms->m_header);

	ms->m_type		= le32_to_cpu(ms->m_type);
	ms->m_nodeid		= le32_to_cpu(ms->m_nodeid);
	ms->m_pid		= le32_to_cpu(ms->m_pid);
	ms->m_lkid		= le32_to_cpu(ms->m_lkid);
	ms->m_remid		= le32_to_cpu(ms->m_remid);
	ms->m_parent_lkid	= le32_to_cpu(ms->m_parent_lkid);
	ms->m_parent_remid	= le32_to_cpu(ms->m_parent_remid);
	ms->m_exflags		= le32_to_cpu(ms->m_exflags);
	ms->m_sbflags		= le32_to_cpu(ms->m_sbflags);
	ms->m_flags		= le32_to_cpu(ms->m_flags);
	ms->m_lvbseq		= le32_to_cpu(ms->m_lvbseq);
	ms->m_hash		= le32_to_cpu(ms->m_hash);
	ms->m_status		= le32_to_cpu(ms->m_status);
	ms->m_grmode		= le32_to_cpu(ms->m_grmode);
	ms->m_rqmode		= le32_to_cpu(ms->m_rqmode);
	ms->m_bastmode		= le32_to_cpu(ms->m_bastmode);
	ms->m_asts		= le32_to_cpu(ms->m_asts);
	ms->m_result		= from_dlm_errno(le32_to_cpu(ms->m_result));
}