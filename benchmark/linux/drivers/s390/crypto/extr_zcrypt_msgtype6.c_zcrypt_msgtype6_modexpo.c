#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct zcrypt_queue {int /*<<< orphan*/  queue; } ;
struct response_type {int /*<<< orphan*/  work; int /*<<< orphan*/  type; } ;
struct ica_rsa_modexpo {int /*<<< orphan*/  outputdatalength; int /*<<< orphan*/  outputdata; } ;
struct ap_message {int rc; void* message; struct response_type* private; scalar_t__ psmid; int /*<<< orphan*/  receive; } ;
struct TYPE_2__ {scalar_t__ pid; } ;

/* Variables and functions */
 int /*<<< orphan*/  CEXXC_RESPONSE_TYPE_ICA ; 
 long ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int ICAMEX_msg_to_type6MEX_msgX (struct zcrypt_queue*,struct ap_message*,struct ica_rsa_modexpo*) ; 
 int /*<<< orphan*/  ap_cancel_message (int /*<<< orphan*/ ,struct ap_message*) ; 
 int /*<<< orphan*/  ap_init_message (struct ap_message*) ; 
 int /*<<< orphan*/  ap_queue_message (int /*<<< orphan*/ ,struct ap_message*) ; 
 scalar_t__ atomic_inc_return (int /*<<< orphan*/ *) ; 
 int convert_response_ica (struct zcrypt_queue*,struct ap_message*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_1__* current ; 
 int /*<<< orphan*/  free_page (unsigned long) ; 
 scalar_t__ get_zeroed_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int wait_for_completion_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  zcrypt_msgtype6_receive ; 
 int /*<<< orphan*/  zcrypt_step ; 

__attribute__((used)) static long zcrypt_msgtype6_modexpo(struct zcrypt_queue *zq,
				  struct ica_rsa_modexpo *mex)
{
	struct ap_message ap_msg;
	struct response_type resp_type = {
		.type = CEXXC_RESPONSE_TYPE_ICA,
	};
	int rc;

	ap_init_message(&ap_msg);
	ap_msg.message = (void *) get_zeroed_page(GFP_KERNEL);
	if (!ap_msg.message)
		return -ENOMEM;
	ap_msg.receive = zcrypt_msgtype6_receive;
	ap_msg.psmid = (((unsigned long long) current->pid) << 32) +
				atomic_inc_return(&zcrypt_step);
	ap_msg.private = &resp_type;
	rc = ICAMEX_msg_to_type6MEX_msgX(zq, &ap_msg, mex);
	if (rc)
		goto out_free;
	init_completion(&resp_type.work);
	ap_queue_message(zq->queue, &ap_msg);
	rc = wait_for_completion_interruptible(&resp_type.work);
	if (rc == 0) {
		rc = ap_msg.rc;
		if (rc == 0)
			rc = convert_response_ica(zq, &ap_msg,
						  mex->outputdata,
						  mex->outputdatalength);
	} else
		/* Signal pending. */
		ap_cancel_message(zq->queue, &ap_msg);
out_free:
	free_page((unsigned long) ap_msg.message);
	return rc;
}