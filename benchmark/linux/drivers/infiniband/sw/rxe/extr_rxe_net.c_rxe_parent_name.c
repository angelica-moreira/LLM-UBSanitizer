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
struct rxe_dev {TYPE_1__* ndev; } ;
struct TYPE_2__ {char const* name; } ;

/* Variables and functions */

const char *rxe_parent_name(struct rxe_dev *rxe, unsigned int port_num)
{
	return rxe->ndev->name;
}