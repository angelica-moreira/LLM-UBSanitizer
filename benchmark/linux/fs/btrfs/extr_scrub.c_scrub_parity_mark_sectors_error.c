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
struct scrub_parity {int /*<<< orphan*/  ebitmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  __scrub_mark_bitmap (struct scrub_parity*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void scrub_parity_mark_sectors_error(struct scrub_parity *sparity,
						   u64 start, u64 len)
{
	__scrub_mark_bitmap(sparity, sparity->ebitmap, start, len);
}