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
typedef  scalar_t__ __le64 ;

/* Variables and functions */
 int /*<<< orphan*/  EMPTY_SLOT ; 
 size_t EMPTY_SLOT_INDEX ; 
 scalar_t__ cpu_to_le64 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool xgene_enet_is_desc_slot_empty(void *desc_slot_ptr)
{
	__le64 *desc_slot = desc_slot_ptr;

	return (desc_slot[EMPTY_SLOT_INDEX] == cpu_to_le64(EMPTY_SLOT));
}