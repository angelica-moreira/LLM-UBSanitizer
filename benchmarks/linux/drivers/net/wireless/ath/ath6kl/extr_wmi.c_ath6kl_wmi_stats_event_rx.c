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
typedef  int /*<<< orphan*/  u8 ;
struct wmi {int dummy; } ;
struct ath6kl_vif {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ath6kl_tgt_stats_event (struct ath6kl_vif*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int ath6kl_wmi_stats_event_rx(struct wmi *wmi, u8 *datap, int len,
				     struct ath6kl_vif *vif)
{
	ath6kl_tgt_stats_event(vif, datap, len);

	return 0;
}