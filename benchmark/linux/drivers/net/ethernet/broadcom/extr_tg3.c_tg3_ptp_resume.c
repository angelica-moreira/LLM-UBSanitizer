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
struct tg3 {scalar_t__ ptp_adjust; } ;

/* Variables and functions */
 int /*<<< orphan*/  PTP_CAPABLE ; 
 int /*<<< orphan*/  ktime_get_real () ; 
 scalar_t__ ktime_to_ns (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tg3_flag (struct tg3*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tg3_refclk_write (struct tg3*,scalar_t__) ; 

__attribute__((used)) static void tg3_ptp_resume(struct tg3 *tp)
{
	if (!tg3_flag(tp, PTP_CAPABLE))
		return;

	tg3_refclk_write(tp, ktime_to_ns(ktime_get_real()) + tp->ptp_adjust);
	tp->ptp_adjust = 0;
}