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
struct tcf_meta_info {int dummy; } ;
struct sk_buff {int /*<<< orphan*/  mark; } ;

/* Variables and functions */
 int ife_encode_meta_u32 (int /*<<< orphan*/ ,void*,struct tcf_meta_info*) ; 

__attribute__((used)) static int skbmark_encode(struct sk_buff *skb, void *skbdata,
			  struct tcf_meta_info *e)
{
	u32 ifemark = skb->mark;

	return ife_encode_meta_u32(ifemark, skbdata, e);
}