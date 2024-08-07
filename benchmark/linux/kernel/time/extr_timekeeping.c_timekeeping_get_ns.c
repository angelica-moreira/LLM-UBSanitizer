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
typedef  int /*<<< orphan*/  u64 ;
struct tk_read_base {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  timekeeping_delta_to_ns (struct tk_read_base const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  timekeeping_get_delta (struct tk_read_base const*) ; 

__attribute__((used)) static inline u64 timekeeping_get_ns(const struct tk_read_base *tkr)
{
	u64 delta;

	delta = timekeeping_get_delta(tkr);
	return timekeeping_delta_to_ns(tkr, delta);
}