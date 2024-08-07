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
struct mlx4_dev {int dummy; } ;

/* Variables and functions */
 scalar_t__ mlx4_is_guest_proxy (struct mlx4_dev*,int,int) ; 
 scalar_t__ mlx4_is_master (struct mlx4_dev*) ; 
 scalar_t__ mlx4_is_qp_reserved (struct mlx4_dev*,int) ; 

__attribute__((used)) static int valid_reserved(struct mlx4_dev *dev, int slave, int qpn)
{
	return mlx4_is_qp_reserved(dev, qpn) &&
		(mlx4_is_master(dev) || mlx4_is_guest_proxy(dev, slave, qpn));
}