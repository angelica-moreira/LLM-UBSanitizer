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
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct ceph_pagelist {int /*<<< orphan*/  length; } ;
struct ceph_osd_request {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  request_data; } ;
struct ceph_osd_req_op {int /*<<< orphan*/  indata_len; TYPE_1__ notify_ack; } ;

/* Variables and functions */
 int /*<<< orphan*/  CEPH_OSD_OP_NOTIFY_ACK ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_NOIO ; 
 struct ceph_osd_req_op* _osd_req_op_init (struct ceph_osd_request*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ceph_osd_data_pagelist_init (int /*<<< orphan*/ *,struct ceph_pagelist*) ; 
 struct ceph_pagelist* ceph_pagelist_alloc (int /*<<< orphan*/ ) ; 
 int ceph_pagelist_append (struct ceph_pagelist*,void*,int /*<<< orphan*/ ) ; 
 int ceph_pagelist_encode_32 (struct ceph_pagelist*,int /*<<< orphan*/ ) ; 
 int ceph_pagelist_encode_64 (struct ceph_pagelist*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ceph_pagelist_release (struct ceph_pagelist*) ; 

__attribute__((used)) static int osd_req_op_notify_ack_init(struct ceph_osd_request *req, int which,
				      u64 notify_id, u64 cookie, void *payload,
				      u32 payload_len)
{
	struct ceph_osd_req_op *op;
	struct ceph_pagelist *pl;
	int ret;

	op = _osd_req_op_init(req, which, CEPH_OSD_OP_NOTIFY_ACK, 0);

	pl = ceph_pagelist_alloc(GFP_NOIO);
	if (!pl)
		return -ENOMEM;

	ret = ceph_pagelist_encode_64(pl, notify_id);
	ret |= ceph_pagelist_encode_64(pl, cookie);
	if (payload) {
		ret |= ceph_pagelist_encode_32(pl, payload_len);
		ret |= ceph_pagelist_append(pl, payload, payload_len);
	} else {
		ret |= ceph_pagelist_encode_32(pl, 0);
	}
	if (ret) {
		ceph_pagelist_release(pl);
		return -ENOMEM;
	}

	ceph_osd_data_pagelist_init(&op->notify_ack.request_data, pl);
	op->indata_len = pl->length;
	return 0;
}