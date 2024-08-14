#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u_short ;
typedef  int u16 ;
struct atm_dev {int dummy; } ;
struct TYPE_3__ {scalar_t__ reass_reg; scalar_t__ reass_ram; } ;
typedef  TYPE_1__ IADEV ;

/* Variables and functions */
 int EXCPQ_EMPTY ; 
 scalar_t__ EXCP_Q_ED_ADR ; 
 scalar_t__ EXCP_Q_RD_PTR ; 
 scalar_t__ EXCP_Q_ST_ADR ; 
 scalar_t__ EXCP_Q_WR_PTR ; 
 int /*<<< orphan*/  IF_ERR (int /*<<< orphan*/ ) ; 
 TYPE_1__* INPH_IA_DEV (struct atm_dev*) ; 
 scalar_t__ STATE_REG ; 
 int /*<<< orphan*/  printk (char*,...) ; 
 int readl (scalar_t__) ; 
 int readw (scalar_t__) ; 
 int /*<<< orphan*/  writew (int,scalar_t__) ; 

__attribute__((used)) static void rx_excp_rcvd(struct atm_dev *dev)  
{  
#if 0 /* closing the receiving size will cause too many excp int */  
  IADEV *iadev;  
  u_short state;  
  u_short excpq_rd_ptr;  
  //u_short *ptr;  
  int vci, error = 1;  
  iadev = INPH_IA_DEV(dev);  
  state = readl(iadev->reass_reg + STATE_REG) & 0xffff;  
  while((state & EXCPQ_EMPTY) != EXCPQ_EMPTY)  
  { printk("state = %x \n", state); 
        excpq_rd_ptr = readw(iadev->reass_reg + EXCP_Q_RD_PTR) & 0xffff;  
 printk("state = %x excpq_rd_ptr = %x \n", state, excpq_rd_ptr); 
        if (excpq_rd_ptr == *(u16*)(iadev->reass_reg + EXCP_Q_WR_PTR))
            IF_ERR(printk("excpq_rd_ptr is wrong!!!\n");)
        // TODO: update exception stat
	vci = readw(iadev->reass_ram+excpq_rd_ptr);  
	error = readw(iadev->reass_ram+excpq_rd_ptr+2) & 0x0007;  
        // pwang_test
	excpq_rd_ptr += 4;  
	if (excpq_rd_ptr > (readw(iadev->reass_reg + EXCP_Q_ED_ADR)& 0xffff))  
 	    excpq_rd_ptr = readw(iadev->reass_reg + EXCP_Q_ST_ADR)& 0xffff;
	writew( excpq_rd_ptr, iadev->reass_reg + EXCP_Q_RD_PTR);  
        state = readl(iadev->reass_reg + STATE_REG) & 0xffff;  
  }  
#endif
}