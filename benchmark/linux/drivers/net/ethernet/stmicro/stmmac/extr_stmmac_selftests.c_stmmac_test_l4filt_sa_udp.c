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
typedef  int u16 ;
struct stmmac_priv {int dummy; } ;

/* Variables and functions */
 int __stmmac_test_l4filt (struct stmmac_priv*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int stmmac_test_l4filt_sa_udp(struct stmmac_priv *priv)
{
	u16 dummy_port = 0x123;

	return __stmmac_test_l4filt(priv, 0, dummy_port, 0, ~0, true);
}