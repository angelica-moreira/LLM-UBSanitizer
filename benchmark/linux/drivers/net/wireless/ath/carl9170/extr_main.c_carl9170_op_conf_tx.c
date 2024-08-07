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
typedef  size_t u16 ;
struct ieee80211_vif {int dummy; } ;
struct ieee80211_tx_queue_params {int dummy; } ;
struct ieee80211_hw {struct ar9170* priv; } ;
struct ar9170 {int /*<<< orphan*/  mutex; int /*<<< orphan*/ * edcf; } ;

/* Variables and functions */
 size_t* ar9170_qmap ; 
 int carl9170_set_qos (struct ar9170*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,struct ieee80211_tx_queue_params const*,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int carl9170_op_conf_tx(struct ieee80211_hw *hw,
			       struct ieee80211_vif *vif, u16 queue,
			       const struct ieee80211_tx_queue_params *param)
{
	struct ar9170 *ar = hw->priv;
	int ret;

	mutex_lock(&ar->mutex);
	memcpy(&ar->edcf[ar9170_qmap[queue]], param, sizeof(*param));
	ret = carl9170_set_qos(ar);
	mutex_unlock(&ar->mutex);
	return ret;
}