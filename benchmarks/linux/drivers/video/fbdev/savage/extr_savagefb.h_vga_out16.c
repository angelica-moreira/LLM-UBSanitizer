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
typedef  int /*<<< orphan*/  u16 ;
struct savagefb_par {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  savage_out16 (int,int /*<<< orphan*/ ,struct savagefb_par*) ; 

__attribute__((used)) static inline void vga_out16(int addr, u16 val, struct savagefb_par *par)
{
	savage_out16(0x8000 + addr, val, par);
}