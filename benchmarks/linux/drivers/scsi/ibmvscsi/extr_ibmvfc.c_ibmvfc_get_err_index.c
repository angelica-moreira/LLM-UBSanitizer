#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u16 ;
struct TYPE_3__ {scalar_t__ status; scalar_t__ error; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 TYPE_1__* cmd_status ; 

__attribute__((used)) static int ibmvfc_get_err_index(u16 status, u16 error)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(cmd_status); i++)
		if ((cmd_status[i].status & status) == cmd_status[i].status &&
		    cmd_status[i].error == error)
			return i;

	return -EINVAL;
}