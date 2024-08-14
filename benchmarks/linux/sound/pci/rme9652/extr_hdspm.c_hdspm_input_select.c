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
struct hdspm {int control_register; } ;

/* Variables and functions */
 int HDSPM_InputSelect0 ; 

__attribute__((used)) static int hdspm_input_select(struct hdspm * hdspm)
{
	return (hdspm->control_register & HDSPM_InputSelect0) ? 1 : 0;
}