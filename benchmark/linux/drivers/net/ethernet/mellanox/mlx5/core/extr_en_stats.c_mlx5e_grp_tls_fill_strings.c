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
typedef  int /*<<< orphan*/  u8 ;
struct mlx5e_priv {int dummy; } ;

/* Variables and functions */
 int ETH_GSTRING_LEN ; 
 int mlx5e_tls_get_strings (struct mlx5e_priv*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int mlx5e_grp_tls_fill_strings(struct mlx5e_priv *priv, u8 *data,
				      int idx)
{
	return idx + mlx5e_tls_get_strings(priv, data + idx * ETH_GSTRING_LEN);
}