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
 int /*<<< orphan*/  DRVNAME ; 
 int EBUSY ; 
 int /*<<< orphan*/  outb (int,int) ; 
 int /*<<< orphan*/  request_muxed_region (int,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int superio_enter(int sio_cip)
{
	if (!request_muxed_region(sio_cip, 2, DRVNAME))
		return -EBUSY;

	outb(0x87, sio_cip);
	outb(0x87, sio_cip);

	return 0;
}