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
typedef  int u32 ;

/* Variables and functions */
 int NFP_CPP_TARGET_ID_MASK ; 

__attribute__((used)) static inline u8 NFP_CPP_ID_TARGET_of(u32 id)
{
	return (id >> 24) & NFP_CPP_TARGET_ID_MASK;
}