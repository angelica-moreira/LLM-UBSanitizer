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
typedef  int u8 ;

/* Variables and functions */
 int NVR_BITIN ; 
 int NVR_CLOCK ; 
 int NVR_SELECT ; 
 unsigned long TRM_S1040_GEN_NVRAM ; 
 int inb (unsigned long) ; 
 int /*<<< orphan*/  outb (int,unsigned long) ; 
 int /*<<< orphan*/  trms1040_wait_30us (unsigned long) ; 
 int /*<<< orphan*/  trms1040_write_cmd (unsigned long,int,int) ; 

__attribute__((used)) static u8 trms1040_get_data(unsigned long io_port, u8 addr)
{
	int i;
	u8 read_byte;
	u8 result = 0;

	/* Send read command & address */
	trms1040_write_cmd(io_port, 0x06, addr);

	/* read data */
	for (i = 0; i < 8; i++) {
		outb((NVR_SELECT | NVR_CLOCK), io_port + TRM_S1040_GEN_NVRAM);
		trms1040_wait_30us(io_port);
		outb(NVR_SELECT, io_port + TRM_S1040_GEN_NVRAM);

		/* Get data bit while falling edge */
		read_byte = inb(io_port + TRM_S1040_GEN_NVRAM);
		result <<= 1;
		if (read_byte & NVR_BITIN)
			result |= 1;

		trms1040_wait_30us(io_port);
	}

	/* Disable chip select */
	outb(0, io_port + TRM_S1040_GEN_NVRAM);
	return result;
}