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
struct traffic_stats {int dummy; } ;
struct il_priv {int /*<<< orphan*/  rx_stats; int /*<<< orphan*/  tx_stats; } ;

/* Variables and functions */
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
il_clear_traffic_stats(struct il_priv *il)
{
	memset(&il->tx_stats, 0, sizeof(struct traffic_stats));
	memset(&il->rx_stats, 0, sizeof(struct traffic_stats));
}