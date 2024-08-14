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
typedef  size_t u8 ;

/* Variables and functions */
 size_t __crc (size_t*) ; 
 size_t* rfcomm_crc_table ; 

__attribute__((used)) static inline u8 __fcs2(u8 *data)
{
	return 0xff - rfcomm_crc_table[__crc(data) ^ data[2]];
}