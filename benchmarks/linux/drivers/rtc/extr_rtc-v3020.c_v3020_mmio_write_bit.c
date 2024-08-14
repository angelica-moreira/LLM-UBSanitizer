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
struct v3020 {unsigned char leftshift; int /*<<< orphan*/  ioaddress; } ;

/* Variables and functions */
 int /*<<< orphan*/  writel (unsigned char,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void v3020_mmio_write_bit(struct v3020 *chip, unsigned char bit)
{
	writel(bit << chip->leftshift, chip->ioaddress);
}