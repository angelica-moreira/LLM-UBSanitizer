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
typedef  int u32 ;

/* Variables and functions */
 int I40E_NVM_TRANS_MASK ; 
 int I40E_NVM_TRANS_SHIFT ; 

__attribute__((used)) static inline u8 i40e_nvmupd_get_transaction(u32 val)
{
	return (u8)((val & I40E_NVM_TRANS_MASK) >> I40E_NVM_TRANS_SHIFT);
}