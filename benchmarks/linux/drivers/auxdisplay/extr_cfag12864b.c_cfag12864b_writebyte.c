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
 int /*<<< orphan*/  cfag12864b_di (int) ; 
 int /*<<< orphan*/  cfag12864b_e (int) ; 
 int /*<<< orphan*/  ks0108_writedata (unsigned char) ; 

__attribute__((used)) static void cfag12864b_writebyte(unsigned char byte)
{
	cfag12864b_di(1);
	cfag12864b_e(1);
	ks0108_writedata(byte);
	cfag12864b_e(0);
}