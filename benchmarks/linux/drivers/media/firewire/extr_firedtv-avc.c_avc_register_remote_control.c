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
struct firedtv {int avc_data_length; int /*<<< orphan*/  avc_mutex; scalar_t__ avc_data; } ;
struct avc_command_frame {int subunit; scalar_t__* operand; int /*<<< orphan*/  opcode; int /*<<< orphan*/  ctype; } ;

/* Variables and functions */
 int /*<<< orphan*/  AVC_CTYPE_NOTIFY ; 
 int /*<<< orphan*/  AVC_OPCODE_VENDOR ; 
 int AVC_SUBUNIT_TYPE_UNIT ; 
 scalar_t__ SFE_VENDOR_DE_COMPANYID_0 ; 
 scalar_t__ SFE_VENDOR_DE_COMPANYID_1 ; 
 scalar_t__ SFE_VENDOR_DE_COMPANYID_2 ; 
 scalar_t__ SFE_VENDOR_OPCODE_REGISTER_REMOTE_CONTROL ; 
 int avc_write (struct firedtv*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

int avc_register_remote_control(struct firedtv *fdtv)
{
	struct avc_command_frame *c = (void *)fdtv->avc_data;
	int ret;

	mutex_lock(&fdtv->avc_mutex);

	c->ctype   = AVC_CTYPE_NOTIFY;
	c->subunit = AVC_SUBUNIT_TYPE_UNIT | 7;
	c->opcode  = AVC_OPCODE_VENDOR;

	c->operand[0] = SFE_VENDOR_DE_COMPANYID_0;
	c->operand[1] = SFE_VENDOR_DE_COMPANYID_1;
	c->operand[2] = SFE_VENDOR_DE_COMPANYID_2;
	c->operand[3] = SFE_VENDOR_OPCODE_REGISTER_REMOTE_CONTROL;
	c->operand[4] = 0; /* padding */

	fdtv->avc_data_length = 8;
	ret = avc_write(fdtv);

	/* FIXME: check response code? */

	mutex_unlock(&fdtv->avc_mutex);

	return ret;
}