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
typedef  int /*<<< orphan*/  gfp_t ;

/* Variables and functions */
 void* amiga_chip_alloc (long,char*) ; 

__attribute__((used)) static void *AmiAlloc(unsigned int size, gfp_t flags)
{
	return amiga_chip_alloc((long)size, "dmasound [Paula]");
}