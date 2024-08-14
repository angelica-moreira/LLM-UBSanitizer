#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct mlx5_modify_raw_qp_param {int set_mask; int rq_q_ctr_id; } ;
struct TYPE_6__ {int /*<<< orphan*/  qpn; } ;
struct TYPE_7__ {TYPE_2__ mqp; } ;
struct mlx5_ib_rq {int state; TYPE_3__ base; } ;
struct TYPE_5__ {int /*<<< orphan*/  dev; } ;
struct mlx5_ib_dev {int /*<<< orphan*/  mdev; TYPE_1__ ib_dev; } ;
struct ib_pd {int dummy; } ;
struct TYPE_8__ {int uid; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* MLX5_ADDR_OF (void*,void*,int /*<<< orphan*/ ) ; 
 scalar_t__ MLX5_CAP_GEN (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MLX5_MODIFY_RQ_IN_MODIFY_BITMASK_RQ_COUNTER_SET_ID ; 
 int MLX5_RAW_QP_MOD_SET_RQ_Q_CTR_ID ; 
 int /*<<< orphan*/  MLX5_SET (void*,void*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  MLX5_SET64 (void*,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int MLX5_ST_SZ_BYTES (void*) ; 
 int /*<<< orphan*/  counter_set_id ; 
 int /*<<< orphan*/  ctx ; 
 int /*<<< orphan*/  dev_info_once (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  kvfree (void*) ; 
 void* kvzalloc (int,int /*<<< orphan*/ ) ; 
 int mlx5_core_modify_rq (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int) ; 
 int /*<<< orphan*/  modify_bitmask ; 
 int /*<<< orphan*/  modify_rq_counter_set_id ; 
 void* modify_rq_in ; 
 int /*<<< orphan*/  rq_state ; 
 int /*<<< orphan*/  state ; 
 TYPE_4__* to_mpd (struct ib_pd*) ; 
 int /*<<< orphan*/  uid ; 

__attribute__((used)) static int modify_raw_packet_qp_rq(
	struct mlx5_ib_dev *dev, struct mlx5_ib_rq *rq, int new_state,
	const struct mlx5_modify_raw_qp_param *raw_qp_param, struct ib_pd *pd)
{
	void *in;
	void *rqc;
	int inlen;
	int err;

	inlen = MLX5_ST_SZ_BYTES(modify_rq_in);
	in = kvzalloc(inlen, GFP_KERNEL);
	if (!in)
		return -ENOMEM;

	MLX5_SET(modify_rq_in, in, rq_state, rq->state);
	MLX5_SET(modify_rq_in, in, uid, to_mpd(pd)->uid);

	rqc = MLX5_ADDR_OF(modify_rq_in, in, ctx);
	MLX5_SET(rqc, rqc, state, new_state);

	if (raw_qp_param->set_mask & MLX5_RAW_QP_MOD_SET_RQ_Q_CTR_ID) {
		if (MLX5_CAP_GEN(dev->mdev, modify_rq_counter_set_id)) {
			MLX5_SET64(modify_rq_in, in, modify_bitmask,
				   MLX5_MODIFY_RQ_IN_MODIFY_BITMASK_RQ_COUNTER_SET_ID);
			MLX5_SET(rqc, rqc, counter_set_id, raw_qp_param->rq_q_ctr_id);
		} else
			dev_info_once(
				&dev->ib_dev.dev,
				"RAW PACKET QP counters are not supported on current FW\n");
	}

	err = mlx5_core_modify_rq(dev->mdev, rq->base.mqp.qpn, in, inlen);
	if (err)
		goto out;

	rq->state = new_state;

out:
	kvfree(in);
	return err;
}