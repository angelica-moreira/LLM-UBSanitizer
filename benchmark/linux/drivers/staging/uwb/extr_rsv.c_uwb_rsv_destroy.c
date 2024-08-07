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
struct uwb_rsv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  uwb_rsv_put (struct uwb_rsv*) ; 

void uwb_rsv_destroy(struct uwb_rsv *rsv)
{
	uwb_rsv_put(rsv);
}