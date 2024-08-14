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
typedef  int /*<<< orphan*/  u16 ;
struct ssb_pcicore {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ssb_write32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline
void pcicore_write32(struct ssb_pcicore *pc, u16 offset, u32 value)
{
	ssb_write32(pc->dev, offset, value);
}