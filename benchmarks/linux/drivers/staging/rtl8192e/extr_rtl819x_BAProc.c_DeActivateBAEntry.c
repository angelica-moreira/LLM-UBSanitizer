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
struct rtllib_device {int dummy; } ;
struct ba_record {int bValid; int /*<<< orphan*/  Timer; } ;

/* Variables and functions */
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void DeActivateBAEntry(struct rtllib_device *ieee, struct ba_record *pBA)
{
	pBA->bValid = false;
	del_timer_sync(&pBA->Timer);
}