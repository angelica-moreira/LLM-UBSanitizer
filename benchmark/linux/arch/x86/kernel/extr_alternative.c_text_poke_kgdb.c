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
 void* __text_poke (void*,void const*,size_t) ; 

void *text_poke_kgdb(void *addr, const void *opcode, size_t len)
{
	return __text_poke(addr, opcode, len);
}