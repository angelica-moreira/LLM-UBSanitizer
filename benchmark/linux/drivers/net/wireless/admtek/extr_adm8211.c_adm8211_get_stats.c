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
struct ieee80211_low_level_stats {int dummy; } ;
struct ieee80211_hw {struct adm8211_priv* priv; } ;
struct adm8211_priv {int /*<<< orphan*/  stats; } ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (struct ieee80211_low_level_stats*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int adm8211_get_stats(struct ieee80211_hw *dev,
			     struct ieee80211_low_level_stats *stats)
{
	struct adm8211_priv *priv = dev->priv;

	memcpy(stats, &priv->stats, sizeof(*stats));

	return 0;
}