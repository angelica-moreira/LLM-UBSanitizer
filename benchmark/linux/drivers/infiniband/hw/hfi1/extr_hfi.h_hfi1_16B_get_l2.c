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
struct hfi1_16b_header {int* lrh; } ;

/* Variables and functions */
 int OPA_16B_L2_MASK ; 
 int OPA_16B_L2_SHIFT ; 

__attribute__((used)) static inline u8 hfi1_16B_get_l2(struct hfi1_16b_header *hdr)
{
	return (u8)((hdr->lrh[1] & OPA_16B_L2_MASK) >> OPA_16B_L2_SHIFT);
}