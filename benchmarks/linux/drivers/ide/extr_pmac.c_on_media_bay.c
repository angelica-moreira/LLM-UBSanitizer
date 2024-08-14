#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {TYPE_1__* mdev; } ;
typedef  TYPE_2__ pmac_ide_hwif_t ;
struct TYPE_4__ {int /*<<< orphan*/ * media_bay; } ;

/* Variables and functions */

__attribute__((used)) static int on_media_bay(pmac_ide_hwif_t *pmif)
{
	return pmif->mdev && pmif->mdev->media_bay != NULL;
}