#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  fw_blocks; } ;
struct f34_data {TYPE_1__ v5; } ;

/* Variables and functions */
 int /*<<< orphan*/  F34_WRITE_FW_BLOCK ; 
 int rmi_f34_write_blocks (struct f34_data*,void const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rmi_f34_write_firmware(struct f34_data *f34, const void *data)
{
	return rmi_f34_write_blocks(f34, data, f34->v5.fw_blocks,
				    F34_WRITE_FW_BLOCK);
}