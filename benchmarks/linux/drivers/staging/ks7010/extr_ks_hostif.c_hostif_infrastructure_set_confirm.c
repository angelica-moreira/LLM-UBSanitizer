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
typedef  int /*<<< orphan*/  u16 ;
struct ks_wlan_private {int infra_status; } ;

/* Variables and functions */
 int /*<<< orphan*/  SME_MODE_SET_CONFIRM ; 
 int /*<<< orphan*/  get_word (struct ks_wlan_private*) ; 
 int /*<<< orphan*/  hostif_sme_enqueue (struct ks_wlan_private*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static
void hostif_infrastructure_set_confirm(struct ks_wlan_private *priv)
{
	u16 result_code;

	result_code = get_word(priv);
	priv->infra_status = 1;	/* infrastructure mode set */
	hostif_sme_enqueue(priv, SME_MODE_SET_CONFIRM);
}