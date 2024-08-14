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

/* Variables and functions */
 int /*<<< orphan*/  OPA_MTU_8192 ; 
 int mtu_to_enum (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int mtu_to_path_mtu(u32 mtu)
{
	return mtu_to_enum(mtu, OPA_MTU_8192);
}