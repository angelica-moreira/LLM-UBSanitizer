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
struct stmmac_priv {int dummy; } ;

/* Variables and functions */
 int stmmac_test_vlanoff_common (struct stmmac_priv*,int) ; 

__attribute__((used)) static int stmmac_test_vlanoff(struct stmmac_priv *priv)
{
	return stmmac_test_vlanoff_common(priv, false);
}