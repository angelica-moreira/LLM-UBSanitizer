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
struct hfi1_devdata {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  sc_group_release_update (struct hfi1_devdata*,unsigned int) ; 

__attribute__((used)) static void is_send_credit_int(struct hfi1_devdata *dd, unsigned int source)
{
	sc_group_release_update(dd, source);
}