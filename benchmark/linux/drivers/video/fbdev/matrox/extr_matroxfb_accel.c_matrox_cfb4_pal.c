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
typedef  unsigned int u_int32_t ;

/* Variables and functions */

__attribute__((used)) static inline void matrox_cfb4_pal(u_int32_t* pal) {
	unsigned int i;
	
	for (i = 0; i < 16; i++) {
		pal[i] = i * 0x11111111U;
	}
}