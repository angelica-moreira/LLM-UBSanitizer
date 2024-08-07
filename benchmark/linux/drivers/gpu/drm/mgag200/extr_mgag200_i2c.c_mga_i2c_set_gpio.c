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
struct mga_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DAC_DATA ; 
 int /*<<< orphan*/  DAC_INDEX ; 
 int /*<<< orphan*/  MGA1064_GEN_IO_CTL ; 
 int /*<<< orphan*/  MGA1064_GEN_IO_DATA ; 
 int RREG8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WREG8 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WREG_DAC (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void mga_i2c_set_gpio(struct mga_device *mdev, int mask, int val)
{
	int tmp;

	WREG8(DAC_INDEX, MGA1064_GEN_IO_CTL);
	tmp = (RREG8(DAC_DATA) & mask) | val;
	WREG_DAC(MGA1064_GEN_IO_CTL, tmp);
	WREG_DAC(MGA1064_GEN_IO_DATA, 0);
}