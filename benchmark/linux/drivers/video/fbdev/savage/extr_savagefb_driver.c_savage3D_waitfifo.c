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
struct savagefb_par {int dummy; } ;

/* Variables and functions */
 int MAXFIFO ; 
 int savage_in32 (int,struct savagefb_par*) ; 

__attribute__((used)) static void
savage3D_waitfifo(struct savagefb_par *par, int space)
{
	int slots = MAXFIFO - space;

	while ((savage_in32(0x48C00, par) & 0x0000ffff) > slots);
}