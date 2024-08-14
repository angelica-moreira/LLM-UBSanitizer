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
struct bfa_ioc_s {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_ADAPTER_MFG_NAME_LEN ; 
 int /*<<< orphan*/  BFA_MFG_NAME ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlcpy (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
bfa_ioc_get_adapter_manufacturer(struct bfa_ioc_s *ioc, char *manufacturer)
{
	memset((void *)manufacturer, 0, BFA_ADAPTER_MFG_NAME_LEN);
	strlcpy(manufacturer, BFA_MFG_NAME, BFA_ADAPTER_MFG_NAME_LEN);
}