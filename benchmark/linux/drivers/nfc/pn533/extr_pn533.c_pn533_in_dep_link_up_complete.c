#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
struct sk_buff {scalar_t__ len; scalar_t__ data; } ;
struct pn533_cmd_jump_dep_response {int status; int /*<<< orphan*/  gt; int /*<<< orphan*/  nfcid3t; } ;
struct pn533 {int tgt_available_prots; int tgt_active_prot; TYPE_2__* nfc_dev; int /*<<< orphan*/  dev; } ;
struct nfc_target {int nfcid1_len; int /*<<< orphan*/  nfcid1; int /*<<< orphan*/  supported_protocols; } ;
struct TYPE_6__ {TYPE_1__* targets; } ;
struct TYPE_5__ {int /*<<< orphan*/  idx; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ IS_ERR (struct sk_buff*) ; 
 int NFC_PROTO_NFC_DEP ; 
 int /*<<< orphan*/  NFC_PROTO_NFC_DEP_MASK ; 
 int /*<<< orphan*/  NFC_RF_INITIATOR ; 
 int PN533_CMD_RET_MASK ; 
 int PN533_CMD_RET_SUCCESS ; 
 int PTR_ERR (struct sk_buff*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  kfree (void*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int nfc_dep_link_is_up (TYPE_2__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nfc_err (int /*<<< orphan*/ ,char*,...) ; 
 int nfc_set_remote_general_bytes (TYPE_2__*,int /*<<< orphan*/ ,scalar_t__) ; 
 int nfc_targets_found (TYPE_2__*,struct nfc_target*,int) ; 

__attribute__((used)) static int pn533_in_dep_link_up_complete(struct pn533 *dev, void *arg,
					 struct sk_buff *resp)
{
	struct pn533_cmd_jump_dep_response *rsp;
	u8 target_gt_len;
	int rc;
	u8 active = *(u8 *)arg;

	kfree(arg);

	if (IS_ERR(resp))
		return PTR_ERR(resp);

	if (dev->tgt_available_prots &&
	    !(dev->tgt_available_prots & (1 << NFC_PROTO_NFC_DEP))) {
		nfc_err(dev->dev,
			"The target does not support DEP\n");
		rc =  -EINVAL;
		goto error;
	}

	rsp = (struct pn533_cmd_jump_dep_response *)resp->data;

	rc = rsp->status & PN533_CMD_RET_MASK;
	if (rc != PN533_CMD_RET_SUCCESS) {
		nfc_err(dev->dev,
			"Bringing DEP link up failed (error 0x%x)\n", rc);
		goto error;
	}

	if (!dev->tgt_available_prots) {
		struct nfc_target nfc_target;

		dev_dbg(dev->dev, "Creating new target\n");

		nfc_target.supported_protocols = NFC_PROTO_NFC_DEP_MASK;
		nfc_target.nfcid1_len = 10;
		memcpy(nfc_target.nfcid1, rsp->nfcid3t, nfc_target.nfcid1_len);
		rc = nfc_targets_found(dev->nfc_dev, &nfc_target, 1);
		if (rc)
			goto error;

		dev->tgt_available_prots = 0;
	}

	dev->tgt_active_prot = NFC_PROTO_NFC_DEP;

	/* ATR_RES general bytes are located at offset 17 */
	target_gt_len = resp->len - 17;
	rc = nfc_set_remote_general_bytes(dev->nfc_dev,
					  rsp->gt, target_gt_len);
	if (rc == 0)
		rc = nfc_dep_link_is_up(dev->nfc_dev,
					dev->nfc_dev->targets[0].idx,
					!active, NFC_RF_INITIATOR);

error:
	dev_kfree_skb(resp);
	return rc;
}