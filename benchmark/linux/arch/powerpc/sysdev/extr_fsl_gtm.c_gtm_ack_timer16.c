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
typedef  int /*<<< orphan*/  u16 ;
struct gtm_timer {int /*<<< orphan*/  gtevr; } ;

/* Variables and functions */
 int /*<<< orphan*/  out_be16 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void gtm_ack_timer16(struct gtm_timer *tmr, u16 events)
{
	out_be16(tmr->gtevr, events);
}