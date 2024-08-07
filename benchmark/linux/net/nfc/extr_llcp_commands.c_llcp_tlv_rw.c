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
typedef  int u8 ;

/* Variables and functions */
 int /*<<< orphan*/  LLCP_TLV_RW ; 
 int llcp_tlv8 (int*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static u8 llcp_tlv_rw(u8 *tlv)
{
	return llcp_tlv8(tlv, LLCP_TLV_RW) & 0xf;
}