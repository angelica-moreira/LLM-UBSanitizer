#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ longLengthID; int /*<<< orphan*/  sequencesStart; int /*<<< orphan*/  sequences; int /*<<< orphan*/  litStart; int /*<<< orphan*/  lit; } ;
typedef  TYPE_1__ seqStore_t ;

/* Variables and functions */

__attribute__((used)) static void ZSTD_resetSeqStore(seqStore_t *ssPtr)
{
	ssPtr->lit = ssPtr->litStart;
	ssPtr->sequences = ssPtr->sequencesStart;
	ssPtr->longLengthID = 0;
}