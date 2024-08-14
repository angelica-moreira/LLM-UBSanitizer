#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  void* u8 ;
struct TYPE_4__ {int /*<<< orphan*/  len; } ;
struct wcn36xx_hal_set_bss_key_req_msg {int enc_type; int num_keys; TYPE_2__ header; TYPE_1__* keys; void* bss_idx; } ;
struct wcn36xx {int /*<<< orphan*/  hal_mutex; int /*<<< orphan*/  hal_rsp_len; int /*<<< orphan*/  hal_buf; } ;
typedef  enum ani_ed_type { ____Placeholder_ani_ed_type } ani_ed_type ;
struct TYPE_3__ {int /*<<< orphan*/  key; void* length; scalar_t__ pae_role; int /*<<< orphan*/  direction; scalar_t__ unicast; void* id; } ;

/* Variables and functions */
 int /*<<< orphan*/  INIT_HAL_MSG (struct wcn36xx_hal_set_bss_key_req_msg,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PREPARE_HAL_BUF (int /*<<< orphan*/ ,struct wcn36xx_hal_set_bss_key_req_msg) ; 
 int /*<<< orphan*/  WCN36XX_HAL_RX_ONLY ; 
 int /*<<< orphan*/  WCN36XX_HAL_SET_BSSKEY_REQ ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,void**,void*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wcn36xx_err (char*,...) ; 
 int wcn36xx_smd_rsp_status_check (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int wcn36xx_smd_send_and_wait (struct wcn36xx*,int /*<<< orphan*/ ) ; 

int wcn36xx_smd_set_bsskey(struct wcn36xx *wcn,
			   enum ani_ed_type enc_type,
			   u8 bssidx,
			   u8 keyidx,
			   u8 keylen,
			   u8 *key)
{
	struct wcn36xx_hal_set_bss_key_req_msg msg_body;
	int ret;

	mutex_lock(&wcn->hal_mutex);
	INIT_HAL_MSG(msg_body, WCN36XX_HAL_SET_BSSKEY_REQ);
	msg_body.bss_idx = bssidx;
	msg_body.enc_type = enc_type;
	msg_body.num_keys = 1;
	msg_body.keys[0].id = keyidx;
	msg_body.keys[0].unicast = 0;
	msg_body.keys[0].direction = WCN36XX_HAL_RX_ONLY;
	msg_body.keys[0].pae_role = 0;
	msg_body.keys[0].length = keylen;
	memcpy(msg_body.keys[0].key, key, keylen);

	PREPARE_HAL_BUF(wcn->hal_buf, msg_body);

	ret = wcn36xx_smd_send_and_wait(wcn, msg_body.header.len);
	if (ret) {
		wcn36xx_err("Sending hal_set_bsskey failed\n");
		goto out;
	}
	ret = wcn36xx_smd_rsp_status_check(wcn->hal_buf, wcn->hal_rsp_len);
	if (ret) {
		wcn36xx_err("hal_set_bsskey response failed err=%d\n", ret);
		goto out;
	}
out:
	mutex_unlock(&wcn->hal_mutex);
	return ret;
}