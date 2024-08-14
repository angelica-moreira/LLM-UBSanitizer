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
struct perf_stat_config {int stats_num; int /*<<< orphan*/ * stats; } ;

/* Variables and functions */
 int /*<<< orphan*/  runtime_stat__exit (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  zfree (int /*<<< orphan*/ **) ; 

__attribute__((used)) static void runtime_stat_delete(struct perf_stat_config *config)
{
	int i;

	if (!config->stats)
		return;

	for (i = 0; i < config->stats_num; i++)
		runtime_stat__exit(&config->stats[i]);

	zfree(&config->stats);
}