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
typedef  int /*<<< orphan*/  ax25_cb ;

/* Variables and functions */
 int /*<<< orphan*/  ax25_std_establish_data_link (int /*<<< orphan*/ *) ; 

void ax25_std_nr_error_recovery(ax25_cb *ax25)
{
	ax25_std_establish_data_link(ax25);
}