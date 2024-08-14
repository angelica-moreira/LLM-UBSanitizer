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
struct se_session {struct iscsi_session* fabric_sess_ptr; } ;
struct iscsi_session {int /*<<< orphan*/  session_index; } ;

/* Variables and functions */

__attribute__((used)) static u32 lio_sess_get_index(struct se_session *se_sess)
{
	struct iscsi_session *sess = se_sess->fabric_sess_ptr;

	return sess->session_index;
}