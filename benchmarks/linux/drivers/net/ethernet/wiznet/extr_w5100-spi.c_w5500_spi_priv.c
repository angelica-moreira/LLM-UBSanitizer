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
struct w5500_spi_priv {int dummy; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 struct w5500_spi_priv* w5100_ops_priv (struct net_device*) ; 

__attribute__((used)) static struct w5500_spi_priv *w5500_spi_priv(struct net_device *ndev)
{
	return w5100_ops_priv(ndev);
}