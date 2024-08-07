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
typedef  scalar_t__ time64_t ;
struct timespec64 {long tv_nsec; scalar_t__ tv_sec; } ;
typedef  scalar_t__ int64_t ;

/* Variables and functions */
 int /*<<< orphan*/  HP_SDC_CMD_LOAD_FHS ; 
 scalar_t__ hp_sdc_rtc_read_i8042timer (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline int hp_sdc_rtc_read_fhs(struct timespec64 *res) {
	int64_t raw;
	unsigned int tenms;

	raw = hp_sdc_rtc_read_i8042timer(HP_SDC_CMD_LOAD_FHS, 2);
	if (raw < 0) return -1;

	tenms = (unsigned int)raw & 0xffff;

	res->tv_nsec = (long)(tenms % 100) * 10000 * 1000;
	res->tv_sec  = (time64_t)(tenms / 100);

	return 0;
}