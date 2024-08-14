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
struct TYPE_2__ {int link_state; } ;
struct mlx4_en_priv {TYPE_1__ port_state; int /*<<< orphan*/  port; int /*<<< orphan*/  mdev; } ;

/* Variables and functions */
 int ENOMEM ; 
 scalar_t__ mlx4_en_QUERY_PORT (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mlx4_en_test_link(struct mlx4_en_priv *priv)
{
	if (mlx4_en_QUERY_PORT(priv->mdev, priv->port))
		return -ENOMEM;
	if (priv->port_state.link_state == 1)
		return 0;
	else
		return 1;
}