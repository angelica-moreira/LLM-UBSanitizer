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
struct sk_buff {scalar_t__ len; } ;
struct mlx4_wqe_inline_seg {int dummy; } ;

/* Variables and functions */
 int ALIGN (scalar_t__,int) ; 
 scalar_t__ CTRL_SIZE ; 
 scalar_t__ MLX4_INLINE_ALIGN ; 

__attribute__((used)) static int inline_size(const struct sk_buff *skb)
{
	if (skb->len + CTRL_SIZE + sizeof(struct mlx4_wqe_inline_seg)
	    <= MLX4_INLINE_ALIGN)
		return ALIGN(skb->len + CTRL_SIZE +
			     sizeof(struct mlx4_wqe_inline_seg), 16);
	else
		return ALIGN(skb->len + CTRL_SIZE + 2 *
			     sizeof(struct mlx4_wqe_inline_seg), 16);
}