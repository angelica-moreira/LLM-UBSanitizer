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
struct pvr2_ctrl {int /*<<< orphan*/  hdw; } ;

/* Variables and functions */
 int pvr2_hdw_set_input (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int ctrl_set_input(struct pvr2_ctrl *cptr,int m,int v)
{
	return pvr2_hdw_set_input(cptr->hdw,v);
}