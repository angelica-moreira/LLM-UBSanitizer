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
struct vpdma_dtd {int desc_write_addr; } ;

/* Variables and functions */
 int DTD_WRITE_DESC_MASK ; 
 int DTD_WRITE_DESC_SHIFT ; 

__attribute__((used)) static inline bool dtd_get_write_desc(struct vpdma_dtd *dtd)
{
	return (dtd->desc_write_addr >> DTD_WRITE_DESC_SHIFT) &
							DTD_WRITE_DESC_MASK;
}