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
typedef  int /*<<< orphan*/  u32 ;
struct be_nic_res_desc {int dummy; } ;

/* Variables and functions */
 struct be_nic_res_desc* be_get_nic_desc (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct be_nic_res_desc *be_get_vft_desc(u8 *buf, u32 desc_count,
					       u8 pf_num)
{
	return be_get_nic_desc(buf, desc_count, true, pf_num);
}