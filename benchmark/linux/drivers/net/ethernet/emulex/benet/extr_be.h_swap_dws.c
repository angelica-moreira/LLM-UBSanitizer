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

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  cpu_to_le32 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void swap_dws(void *wrb, int len)
{
#ifdef __BIG_ENDIAN
	u32 *dw = wrb;
	BUG_ON(len % 4);
	do {
		*dw = cpu_to_le32(*dw);
		dw++;
		len -= 4;
	} while (len);
#endif				/* __BIG_ENDIAN */
}