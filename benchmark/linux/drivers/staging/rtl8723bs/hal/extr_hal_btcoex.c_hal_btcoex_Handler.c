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
struct adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  EXhalbtcoutsrc_Periodical (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GLBtCoexist ; 

void hal_btcoex_Handler(struct adapter *padapter)
{
	EXhalbtcoutsrc_Periodical(&GLBtCoexist);
}