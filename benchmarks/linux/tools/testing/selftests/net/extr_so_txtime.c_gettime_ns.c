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
typedef  scalar_t__ uint64_t ;
struct timespec {unsigned long long tv_sec; scalar_t__ tv_nsec; } ;

/* Variables and functions */
 int /*<<< orphan*/  cfg_clockid ; 
 scalar_t__ clock_gettime (int /*<<< orphan*/ ,struct timespec*) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  error (int,int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static uint64_t gettime_ns(void)
{
	struct timespec ts;

	if (clock_gettime(cfg_clockid, &ts))
		error(1, errno, "gettime");

	return ts.tv_sec * (1000ULL * 1000 * 1000) + ts.tv_nsec;
}