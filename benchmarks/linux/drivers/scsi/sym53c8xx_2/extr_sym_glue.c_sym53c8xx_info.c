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
struct Scsi_Host {int dummy; } ;

/* Variables and functions */
 char const* SYM_DRIVER_NAME ; 

__attribute__((used)) static const char *sym53c8xx_info (struct Scsi_Host *host)
{
	return SYM_DRIVER_NAME;
}