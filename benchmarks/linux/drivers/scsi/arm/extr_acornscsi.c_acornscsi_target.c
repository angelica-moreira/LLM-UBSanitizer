#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {TYPE_2__* SCpnt; } ;
struct TYPE_6__ {TYPE_1__* device; } ;
struct TYPE_5__ {char id; } ;
typedef  TYPE_3__ AS_Host ;

/* Variables and functions */

__attribute__((used)) static
char acornscsi_target(AS_Host *host)
{
	if (host->SCpnt)
		return '0' + host->SCpnt->device->id;
	return 'H';
}