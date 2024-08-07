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
struct us_data {char const* scsi_name; } ;
struct Scsi_Host {int dummy; } ;

/* Variables and functions */
 struct us_data* host_to_us (struct Scsi_Host*) ; 

__attribute__((used)) static const char* host_info(struct Scsi_Host *host)
{
	struct us_data *us = host_to_us(host);
	return us->scsi_name;
}