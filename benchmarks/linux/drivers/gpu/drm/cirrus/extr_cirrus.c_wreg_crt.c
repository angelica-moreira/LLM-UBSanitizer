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
typedef  int /*<<< orphan*/  u8 ;
struct cirrus_device {scalar_t__ mmio; } ;

/* Variables and functions */
 scalar_t__ CRT_DATA ; 
 scalar_t__ CRT_INDEX ; 
 int /*<<< orphan*/  iowrite8 (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void wreg_crt(struct cirrus_device *cirrus, u8 reg, u8 val)
{
	iowrite8(reg, cirrus->mmio + CRT_INDEX);
	iowrite8(val, cirrus->mmio + CRT_DATA);
}