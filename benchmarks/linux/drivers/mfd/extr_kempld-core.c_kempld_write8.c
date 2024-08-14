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
struct kempld_device_data {int /*<<< orphan*/  io_data; int /*<<< orphan*/  io_index; } ;

/* Variables and functions */
 int /*<<< orphan*/  iowrite8 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void kempld_write8(struct kempld_device_data *pld, u8 index, u8 data)
{
	iowrite8(index, pld->io_index);
	iowrite8(data, pld->io_data);
}