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
struct iscsi_cls_session {unsigned int target_id; int ida_used; int /*<<< orphan*/  sess_list; int /*<<< orphan*/  dev; int /*<<< orphan*/  sid; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  ISCSI_DBG_TRANS_SESSION (struct iscsi_cls_session*,char*) ; 
 int /*<<< orphan*/  ISCSI_KEVENT_CREATE_SESSION ; 
 unsigned int ISCSI_MAX_TARGET ; 
 int /*<<< orphan*/  KERN_ERR ; 
 int /*<<< orphan*/  atomic_add_return (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_name (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int device_add (int /*<<< orphan*/ *) ; 
 int ida_simple_get (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ida_simple_remove (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  iscsi_cls_session_printk (int /*<<< orphan*/ ,struct iscsi_cls_session*,char*) ; 
 int /*<<< orphan*/  iscsi_sess_ida ; 
 int /*<<< orphan*/  iscsi_session_event (struct iscsi_cls_session*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iscsi_session_nr ; 
 int /*<<< orphan*/  list_add (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sesslist ; 
 int /*<<< orphan*/  sesslock ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  transport_register_device (int /*<<< orphan*/ *) ; 

int iscsi_add_session(struct iscsi_cls_session *session, unsigned int target_id)
{
	unsigned long flags;
	int id = 0;
	int err;

	session->sid = atomic_add_return(1, &iscsi_session_nr);

	if (target_id == ISCSI_MAX_TARGET) {
		id = ida_simple_get(&iscsi_sess_ida, 0, 0, GFP_KERNEL);

		if (id < 0) {
			iscsi_cls_session_printk(KERN_ERR, session,
					"Failure in Target ID Allocation\n");
			return id;
		}
		session->target_id = (unsigned int)id;
		session->ida_used = true;
	} else
		session->target_id = target_id;

	dev_set_name(&session->dev, "session%u", session->sid);
	err = device_add(&session->dev);
	if (err) {
		iscsi_cls_session_printk(KERN_ERR, session,
					 "could not register session's dev\n");
		goto release_ida;
	}
	transport_register_device(&session->dev);

	spin_lock_irqsave(&sesslock, flags);
	list_add(&session->sess_list, &sesslist);
	spin_unlock_irqrestore(&sesslock, flags);

	iscsi_session_event(session, ISCSI_KEVENT_CREATE_SESSION);
	ISCSI_DBG_TRANS_SESSION(session, "Completed session adding\n");
	return 0;

release_ida:
	if (session->ida_used)
		ida_simple_remove(&iscsi_sess_ida, session->target_id);

	return err;
}