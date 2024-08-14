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
typedef  int /*<<< orphan*/  u32 ;
struct ib_ah {int /*<<< orphan*/  device; } ;

/* Variables and functions */
 int /*<<< orphan*/  mthca_destroy_ah (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  to_mah (struct ib_ah*) ; 
 int /*<<< orphan*/  to_mdev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void mthca_ah_destroy(struct ib_ah *ah, u32 flags)
{
	mthca_destroy_ah(to_mdev(ah->device), to_mah(ah));
}