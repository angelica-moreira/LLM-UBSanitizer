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

/* Variables and functions */
 int ENTRY_BITPOS_QWORDS ; 
 int ENTRY_MASK_QWORDS ; 

__attribute__((used)) static inline int get_entry_len(int entry)
{
	return ((entry & ENTRY_MASK_QWORDS) >> ENTRY_BITPOS_QWORDS) << 3;
}