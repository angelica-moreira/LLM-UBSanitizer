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
struct mlme_priv {int /*<<< orphan*/  fw_state; } ;
typedef  int /*<<< orphan*/  sint ;

/* Variables and functions */

__attribute__((used)) static inline sint get_fwstate(struct mlme_priv *pmlmepriv)
{
	return pmlmepriv->fw_state;
}