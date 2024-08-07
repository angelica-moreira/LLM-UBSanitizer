#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct ahd_softc {TYPE_1__* platform_data; } ;
struct TYPE_2__ {int /*<<< orphan*/  host; } ;

/* Variables and functions */
 int /*<<< orphan*/  scsi_unblock_requests (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
ahd_release_simq(struct ahd_softc *ahd)
{
	scsi_unblock_requests(ahd->platform_data->host);
}