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
struct ionic_lif {int dummy; } ;

/* Variables and functions */
 int ionic_lif_rss_config (struct ionic_lif*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int ionic_lif_rss_deinit(struct ionic_lif *lif)
{
	return ionic_lif_rss_config(lif, 0x0, NULL, NULL);
}