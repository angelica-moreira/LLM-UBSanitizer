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
 void* kmalloc (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void *Q40Alloc(unsigned int size, gfp_t flags)
{
         return kmalloc(size, flags); /* change to vmalloc */
}