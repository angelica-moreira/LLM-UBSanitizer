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
struct ufs_sb_private_info {int s_fpb; } ;
struct ufs_buffer_head {int dummy; } ;

/* Variables and functions */
 int* ubh_get_addr (struct ufs_buffer_head*,unsigned int) ; 

__attribute__((used)) static inline void _ubh_clrblock_(struct ufs_sb_private_info * uspi,
	struct ufs_buffer_head * ubh, unsigned begin, unsigned block)
{
	switch (uspi->s_fpb) {
	case 8:
	    	*ubh_get_addr (ubh, begin + block) = 0x00;
	    	return; 
	case 4:
		*ubh_get_addr (ubh, begin + (block >> 1)) &= ~(0x0f << ((block & 0x01) << 2));
		return;
	case 2:
		*ubh_get_addr (ubh, begin + (block >> 2)) &= ~(0x03 << ((block & 0x03) << 1));
		return;
	case 1:
		*ubh_get_addr (ubh, begin + (block >> 3)) &= ~(0x01 << ((block & 0x07)));
		return;
	}
}