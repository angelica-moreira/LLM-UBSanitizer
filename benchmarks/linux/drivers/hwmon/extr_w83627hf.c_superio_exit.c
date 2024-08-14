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
struct w83627hf_sio_data {int /*<<< orphan*/  sioaddr; } ;

/* Variables and functions */
 int /*<<< orphan*/  outb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  release_region (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void
superio_exit(struct w83627hf_sio_data *sio)
{
	outb(0xAA, sio->sioaddr);
	release_region(sio->sioaddr, 2);
}