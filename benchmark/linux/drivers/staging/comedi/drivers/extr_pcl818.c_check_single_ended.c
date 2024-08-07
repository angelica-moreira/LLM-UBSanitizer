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
 int PCL818_STATUS_MUX ; 
 scalar_t__ PCL818_STATUS_REG ; 
 int inb (scalar_t__) ; 

__attribute__((used)) static int check_single_ended(unsigned int port)
{
	if (inb(port + PCL818_STATUS_REG) & PCL818_STATUS_MUX)
		return 1;
	return 0;
}