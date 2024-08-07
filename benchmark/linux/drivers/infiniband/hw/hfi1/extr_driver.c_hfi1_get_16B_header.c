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
struct hfi1_ctxtdata {int dummy; } ;
struct hfi1_16b_header {int dummy; } ;
typedef  int /*<<< orphan*/  __le32 ;

/* Variables and functions */
 scalar_t__ hfi1_get_header (struct hfi1_ctxtdata*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline struct hfi1_16b_header
		*hfi1_get_16B_header(struct hfi1_ctxtdata *rcd,
				     __le32 *rhf_addr)
{
	return (struct hfi1_16b_header *)hfi1_get_header(rcd, rhf_addr);
}