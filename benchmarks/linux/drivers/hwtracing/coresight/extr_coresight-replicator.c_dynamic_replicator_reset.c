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
struct replicator_drvdata {scalar_t__ base; } ;

/* Variables and functions */
 int /*<<< orphan*/  CS_LOCK (scalar_t__) ; 
 int /*<<< orphan*/  CS_UNLOCK (scalar_t__) ; 
 scalar_t__ REPLICATOR_IDFILTER0 ; 
 scalar_t__ REPLICATOR_IDFILTER1 ; 
 int /*<<< orphan*/  coresight_claim_device_unlocked (scalar_t__) ; 
 int /*<<< orphan*/  coresight_disclaim_device_unlocked (scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static void dynamic_replicator_reset(struct replicator_drvdata *drvdata)
{
	CS_UNLOCK(drvdata->base);

	if (!coresight_claim_device_unlocked(drvdata->base)) {
		writel_relaxed(0xff, drvdata->base + REPLICATOR_IDFILTER0);
		writel_relaxed(0xff, drvdata->base + REPLICATOR_IDFILTER1);
		coresight_disclaim_device_unlocked(drvdata->base);
	}

	CS_LOCK(drvdata->base);
}