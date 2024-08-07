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
typedef  int u32 ;
struct hdspm {int dummy; } ;

/* Variables and functions */
 scalar_t__ HDSPM_RD_TCO ; 
 int hdspm_read (struct hdspm*,scalar_t__) ; 

__attribute__((used)) static int hdspm_tco_input_check(struct hdspm *hdspm, u32 mask)
{
	u32 status;
	status = hdspm_read(hdspm, HDSPM_RD_TCO + 4);

	return (status & mask) ? 1 : 0;
}