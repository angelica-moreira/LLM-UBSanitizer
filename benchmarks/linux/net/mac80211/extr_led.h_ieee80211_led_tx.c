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
struct ieee80211_local {int /*<<< orphan*/  tx_led; int /*<<< orphan*/  tx_led_active; } ;

/* Variables and functions */
 unsigned long MAC80211_BLINK_DELAY ; 
 int /*<<< orphan*/  atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  led_trigger_blink_oneshot (int /*<<< orphan*/ *,unsigned long*,unsigned long*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void ieee80211_led_tx(struct ieee80211_local *local)
{
#ifdef CONFIG_MAC80211_LEDS
	unsigned long led_delay = MAC80211_BLINK_DELAY;

	if (!atomic_read(&local->tx_led_active))
		return;
	led_trigger_blink_oneshot(&local->tx_led, &led_delay, &led_delay, 0);
#endif
}