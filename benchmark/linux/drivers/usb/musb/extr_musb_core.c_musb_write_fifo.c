#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct musb_hw_ep {TYPE_2__* musb; } ;
struct TYPE_3__ {void (* write_fifo ) (struct musb_hw_ep*,int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ;} ;
struct TYPE_4__ {TYPE_1__ io; } ;

/* Variables and functions */
 void stub1 (struct musb_hw_ep*,int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 

void musb_write_fifo(struct musb_hw_ep *hw_ep, u16 len, const u8 *src)
{
	return hw_ep->musb->io.write_fifo(hw_ep, len, src);
}