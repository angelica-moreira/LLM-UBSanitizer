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
 int /*<<< orphan*/  CFAG12864B_BIT_CS2 ; 
 int /*<<< orphan*/  cfag12864b_setbit (unsigned char,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void cfag12864b_cs2(unsigned char state)
{
	cfag12864b_setbit(state, CFAG12864B_BIT_CS2);
}