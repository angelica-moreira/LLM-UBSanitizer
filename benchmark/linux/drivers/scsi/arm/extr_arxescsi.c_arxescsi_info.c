#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {char* type; } ;
struct TYPE_7__ {TYPE_2__ scsi; } ;
struct arxescsi_info {TYPE_4__* ec; TYPE_3__ info; } ;
struct Scsi_Host {TYPE_1__* hostt; scalar_t__ hostdata; } ;
struct TYPE_8__ {int slot_no; } ;
struct TYPE_5__ {char* name; } ;

/* Variables and functions */
 char* VERSION ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*,char*,int,char*) ; 

__attribute__((used)) static const char *arxescsi_info(struct Scsi_Host *host)
{
	struct arxescsi_info *info = (struct arxescsi_info *)host->hostdata;
	static char string[150];

	sprintf(string, "%s (%s) in slot %d v%s",
		host->hostt->name, info->info.scsi.type, info->ec->slot_no,
		VERSION);

	return string;
}