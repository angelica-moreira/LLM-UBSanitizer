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
struct mlx5e_priv {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int mlx5i_pkey_init_rx(struct mlx5e_priv *priv)
{
	/* Since the rx resources are shared between child and parent, the
	 * parent interface is taking care of rx resource allocation and init
	 */
	return 0;
}