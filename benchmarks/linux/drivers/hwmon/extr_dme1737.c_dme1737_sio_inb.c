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

/* Variables and functions */
 int inb (int) ; 
 int /*<<< orphan*/  outb (int,int) ; 

__attribute__((used)) static inline int dme1737_sio_inb(int sio_cip, int reg)
{
	outb(reg, sio_cip);
	return inb(sio_cip + 1);
}