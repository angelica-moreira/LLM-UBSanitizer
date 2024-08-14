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
struct sky2_hw {unsigned int regs; } ;

/* Variables and functions */
 int /*<<< orphan*/  readw (unsigned int) ; 

__attribute__((used)) static inline u16 sky2_read16(const struct sky2_hw *hw, unsigned reg)
{
	return readw(hw->regs + reg);
}