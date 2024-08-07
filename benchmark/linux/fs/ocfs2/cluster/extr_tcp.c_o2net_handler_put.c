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
struct o2net_msg_handler {int /*<<< orphan*/  nh_kref; } ;

/* Variables and functions */
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  o2net_handler_kref_release ; 

__attribute__((used)) static void o2net_handler_put(struct o2net_msg_handler *nmh)
{
	kref_put(&nmh->nh_kref, o2net_handler_kref_release);
}