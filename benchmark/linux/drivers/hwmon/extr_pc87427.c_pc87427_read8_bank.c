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
struct pc87427_data {size_t* address; } ;

/* Variables and functions */
 size_t PC87427_REG_BANK ; 
 int inb (size_t) ; 
 int /*<<< orphan*/  outb (size_t,size_t) ; 

__attribute__((used)) static inline int pc87427_read8_bank(struct pc87427_data *data, u8 ldi,
				     u8 bank, u8 reg)
{
	outb(bank, data->address[ldi] + PC87427_REG_BANK);
	return inb(data->address[ldi] + reg);
}