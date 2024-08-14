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
struct TYPE_2__ {scalar_t__ link_speed; } ;
struct mlx4_en_priv {TYPE_1__ port_state; int /*<<< orphan*/  port; int /*<<< orphan*/  mdev; } ;

/* Variables and functions */
 int ENOMEM ; 
 scalar_t__ SPEED_100 ; 
 scalar_t__ SPEED_1000 ; 
 scalar_t__ SPEED_10000 ; 
 scalar_t__ SPEED_20000 ; 
 scalar_t__ SPEED_40000 ; 
 scalar_t__ SPEED_56000 ; 
 scalar_t__ mlx4_en_QUERY_PORT (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mlx4_en_test_speed(struct mlx4_en_priv *priv)
{

	if (mlx4_en_QUERY_PORT(priv->mdev, priv->port))
		return -ENOMEM;

	/* The device supports 100M, 1G, 10G, 20G, 40G and 56G speed */
	if (priv->port_state.link_speed != SPEED_100 &&
	    priv->port_state.link_speed != SPEED_1000 &&
	    priv->port_state.link_speed != SPEED_10000 &&
	    priv->port_state.link_speed != SPEED_20000 &&
	    priv->port_state.link_speed != SPEED_40000 &&
	    priv->port_state.link_speed != SPEED_56000)
		return priv->port_state.link_speed;

	return 0;
}