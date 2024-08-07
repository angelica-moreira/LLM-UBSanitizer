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
struct kbd_data {unsigned char diacr; } ;

/* Variables and functions */
 unsigned char handle_diacr (struct kbd_data*,unsigned char) ; 
 unsigned char* ret_diacr ; 

__attribute__((used)) static void
k_dead(struct kbd_data *kbd, unsigned char value)
{
	value = ret_diacr[value];
	kbd->diacr = (kbd->diacr ? handle_diacr(kbd, value) : value);
}