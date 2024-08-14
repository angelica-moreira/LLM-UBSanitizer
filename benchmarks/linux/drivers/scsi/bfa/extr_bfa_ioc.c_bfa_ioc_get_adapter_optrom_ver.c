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
struct bfa_ioc_s {TYPE_1__* attr; } ;
struct TYPE_2__ {int /*<<< orphan*/  optrom_version; } ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_VERSION_LEN ; 
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
bfa_ioc_get_adapter_optrom_ver(struct bfa_ioc_s *ioc, char *optrom_ver)
{
	memset((void *)optrom_ver, 0, BFA_VERSION_LEN);
	memcpy(optrom_ver, ioc->attr->optrom_version,
		      BFA_VERSION_LEN);
}