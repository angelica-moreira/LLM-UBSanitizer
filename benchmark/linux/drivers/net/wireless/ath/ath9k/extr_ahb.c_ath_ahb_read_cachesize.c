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
struct ath_common {int dummy; } ;

/* Variables and functions */
 int L1_CACHE_BYTES ; 

__attribute__((used)) static void ath_ahb_read_cachesize(struct ath_common *common, int *csz)
{
	*csz = L1_CACHE_BYTES >> 2;
}