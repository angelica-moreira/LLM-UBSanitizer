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
typedef  int /*<<< orphan*/  u32 ;
struct mlx5_core_dev {int /*<<< orphan*/  board_id; } ;
struct TYPE_2__ {int /*<<< orphan*/  vsd_contd_psid; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  MLX5_ADDR_OF (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MLX5_FLD_SZ_BYTES (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int MLX5_ST_SZ_BYTES (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int mlx5_cmd_query_adapter (struct mlx5_core_dev*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  query_adapter_out ; 
 TYPE_1__ query_adapter_struct ; 

int mlx5_query_board_id(struct mlx5_core_dev *dev)
{
	u32 *out;
	int outlen = MLX5_ST_SZ_BYTES(query_adapter_out);
	int err;

	out = kzalloc(outlen, GFP_KERNEL);
	if (!out)
		return -ENOMEM;

	err = mlx5_cmd_query_adapter(dev, out, outlen);
	if (err)
		goto out;

	memcpy(dev->board_id,
	       MLX5_ADDR_OF(query_adapter_out, out,
			    query_adapter_struct.vsd_contd_psid),
	       MLX5_FLD_SZ_BYTES(query_adapter_out,
				 query_adapter_struct.vsd_contd_psid));

out:
	kfree(out);
	return err;
}