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
typedef  int u32 ;

/* Variables and functions */
 int XHI_OP_SHIFT ; 
 int XHI_OP_WRITE ; 
 int XHI_REGISTER_SHIFT ; 
 int XHI_TYPE_1 ; 
 int XHI_TYPE_SHIFT ; 

__attribute__((used)) static inline u32 hwicap_type_1_write(u32 reg)
{
	return (XHI_TYPE_1 << XHI_TYPE_SHIFT) |
		(reg << XHI_REGISTER_SHIFT) |
		(XHI_OP_WRITE << XHI_OP_SHIFT);
}