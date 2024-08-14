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
struct ipw2100_priv {int status; int /*<<< orphan*/  action_mutex; int /*<<< orphan*/  rf_kill; scalar_t__ stop_rf_kill; } ;

/* Variables and functions */
 int /*<<< orphan*/  HZ ; 
 int /*<<< orphan*/  IPW_DEBUG_RF_KILL (char*,...) ; 
 int STATUS_RF_KILL_SW ; 
 int /*<<< orphan*/  ipw2100_down (struct ipw2100_priv*) ; 
 int /*<<< orphan*/  mod_delayed_work (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ rf_kill_active (struct ipw2100_priv*) ; 
 int /*<<< orphan*/  round_jiffies_relative (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  schedule_reset (struct ipw2100_priv*) ; 
 int /*<<< orphan*/  system_wq ; 

__attribute__((used)) static int ipw_radio_kill_sw(struct ipw2100_priv *priv, int disable_radio)
{
	if ((disable_radio ? 1 : 0) ==
	    (priv->status & STATUS_RF_KILL_SW ? 1 : 0))
		return 0;

	IPW_DEBUG_RF_KILL("Manual SW RF Kill set to: RADIO  %s\n",
			  disable_radio ? "OFF" : "ON");

	mutex_lock(&priv->action_mutex);

	if (disable_radio) {
		priv->status |= STATUS_RF_KILL_SW;
		ipw2100_down(priv);
	} else {
		priv->status &= ~STATUS_RF_KILL_SW;
		if (rf_kill_active(priv)) {
			IPW_DEBUG_RF_KILL("Can not turn radio back on - "
					  "disabled by HW switch\n");
			/* Make sure the RF_KILL check timer is running */
			priv->stop_rf_kill = 0;
			mod_delayed_work(system_wq, &priv->rf_kill,
					 round_jiffies_relative(HZ));
		} else
			schedule_reset(priv);
	}

	mutex_unlock(&priv->action_mutex);
	return 1;
}