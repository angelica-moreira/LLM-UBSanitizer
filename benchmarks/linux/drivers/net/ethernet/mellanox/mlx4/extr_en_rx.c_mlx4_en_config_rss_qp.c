#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct mlx4_qp_context {int /*<<< orphan*/  param3; int /*<<< orphan*/  db_rec_addr; } ;
struct mlx4_qp {int /*<<< orphan*/  event; } ;
struct TYPE_9__ {int /*<<< orphan*/  dma; } ;
struct TYPE_12__ {int /*<<< orphan*/  mtt; TYPE_1__ db; } ;
struct mlx4_en_rx_ring {TYPE_4__ wqres; scalar_t__ fcs_del; int /*<<< orphan*/  cqn; int /*<<< orphan*/  stride; int /*<<< orphan*/  actual_size; } ;
struct mlx4_en_priv {TYPE_3__* dev; struct mlx4_en_dev* mdev; } ;
struct mlx4_en_dev {TYPE_5__* dev; } ;
typedef  enum mlx4_qp_state { ____Placeholder_mlx4_qp_state } mlx4_qp_state ;
struct TYPE_10__ {int flags; } ;
struct TYPE_13__ {TYPE_2__ caps; } ;
struct TYPE_11__ {int features; } ;

/* Variables and functions */
 int ENOMEM ; 
 scalar_t__ ETH_FCS_LEN ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int MLX4_DEV_CAP_FLAG_FCS_KEEP ; 
 int NETIF_F_RXFCS ; 
 int /*<<< orphan*/  cpu_to_be32 (int) ; 
 int /*<<< orphan*/  cpu_to_be64 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  en_err (struct mlx4_en_priv*,char*,int) ; 
 int /*<<< orphan*/  kfree (struct mlx4_qp_context*) ; 
 struct mlx4_qp_context* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct mlx4_qp_context*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mlx4_en_fill_qp_context (struct mlx4_en_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,struct mlx4_qp_context*) ; 
 int /*<<< orphan*/  mlx4_en_sqp_event ; 
 int /*<<< orphan*/  mlx4_en_update_rx_prod_db (struct mlx4_en_rx_ring*) ; 
 int mlx4_qp_alloc (TYPE_5__*,int,struct mlx4_qp*) ; 
 int /*<<< orphan*/  mlx4_qp_free (TYPE_5__*,struct mlx4_qp*) ; 
 int /*<<< orphan*/  mlx4_qp_remove (TYPE_5__*,struct mlx4_qp*) ; 
 int mlx4_qp_to_ready (TYPE_5__*,int /*<<< orphan*/ *,struct mlx4_qp_context*,struct mlx4_qp*,int*) ; 

__attribute__((used)) static int mlx4_en_config_rss_qp(struct mlx4_en_priv *priv, int qpn,
				 struct mlx4_en_rx_ring *ring,
				 enum mlx4_qp_state *state,
				 struct mlx4_qp *qp)
{
	struct mlx4_en_dev *mdev = priv->mdev;
	struct mlx4_qp_context *context;
	int err = 0;

	context = kmalloc(sizeof(*context), GFP_KERNEL);
	if (!context)
		return -ENOMEM;

	err = mlx4_qp_alloc(mdev->dev, qpn, qp);
	if (err) {
		en_err(priv, "Failed to allocate qp #%x\n", qpn);
		goto out;
	}
	qp->event = mlx4_en_sqp_event;

	memset(context, 0, sizeof(*context));
	mlx4_en_fill_qp_context(priv, ring->actual_size, ring->stride, 0, 0,
				qpn, ring->cqn, -1, context);
	context->db_rec_addr = cpu_to_be64(ring->wqres.db.dma);

	/* Cancel FCS removal if FW allows */
	if (mdev->dev->caps.flags & MLX4_DEV_CAP_FLAG_FCS_KEEP) {
		context->param3 |= cpu_to_be32(1 << 29);
		if (priv->dev->features & NETIF_F_RXFCS)
			ring->fcs_del = 0;
		else
			ring->fcs_del = ETH_FCS_LEN;
	} else
		ring->fcs_del = 0;

	err = mlx4_qp_to_ready(mdev->dev, &ring->wqres.mtt, context, qp, state);
	if (err) {
		mlx4_qp_remove(mdev->dev, qp);
		mlx4_qp_free(mdev->dev, qp);
	}
	mlx4_en_update_rx_prod_db(ring);
out:
	kfree(context);
	return err;
}