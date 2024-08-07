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
typedef  void* u32 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  amb_dev ;

/* Variables and functions */
 int DBG_FLOW ; 
 int DBG_IRQ ; 
 int DBG_WARN ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 unsigned char NUM_RX_POOLS ; 
 int /*<<< orphan*/  PRINTD (int,char*,...) ; 
 int /*<<< orphan*/  amb_mem ; 
 int /*<<< orphan*/  fill_rx_pools (int /*<<< orphan*/ *) ; 
 void* interrupt ; 
 int /*<<< orphan*/  offsetof (int /*<<< orphan*/ ,void*) ; 
 void* rd_plain (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rx_take (int /*<<< orphan*/ *,unsigned char) ; 
 int /*<<< orphan*/  tx_take (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wr_plain (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static irqreturn_t interrupt_handler(int irq, void *dev_id) {
  amb_dev * dev = dev_id;
  
  PRINTD (DBG_IRQ|DBG_FLOW, "interrupt_handler: %p", dev_id);
  
  {
    u32 interrupt = rd_plain (dev, offsetof(amb_mem, interrupt));
  
    // for us or someone else sharing the same interrupt
    if (!interrupt) {
      PRINTD (DBG_IRQ, "irq not for me: %d", irq);
      return IRQ_NONE;
    }
    
    // definitely for us
    PRINTD (DBG_IRQ, "FYI: interrupt was %08x", interrupt);
    wr_plain (dev, offsetof(amb_mem, interrupt), -1);
  }
  
  {
    unsigned int irq_work = 0;
    unsigned char pool;
    for (pool = 0; pool < NUM_RX_POOLS; ++pool)
      while (!rx_take (dev, pool))
	++irq_work;
    while (!tx_take (dev))
      ++irq_work;
  
    if (irq_work) {
      fill_rx_pools (dev);

      PRINTD (DBG_IRQ, "work done: %u", irq_work);
    } else {
      PRINTD (DBG_IRQ|DBG_WARN, "no work done");
    }
  }
  
  PRINTD (DBG_IRQ|DBG_FLOW, "interrupt_handler done: %p", dev_id);
  return IRQ_HANDLED;
}