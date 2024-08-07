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
typedef  int /*<<< orphan*/  u8 ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (int*) ; 
 int* zigzag ; 

__attribute__((used)) static void put_qtbl(u8 *p, const u8 *qtbl)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(zigzag); i++)
		p[i] = *(qtbl + zigzag[i]);
}