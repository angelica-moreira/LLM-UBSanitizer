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
struct buffer_head {int dummy; } ;

/* Variables and functions */
 void* ih_item_body (struct buffer_head const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  item_head (struct buffer_head const*,int) ; 

__attribute__((used)) static inline void *item_body(const struct buffer_head *bh, int item_num)
{
	return ih_item_body(bh, item_head(bh, item_num));
}