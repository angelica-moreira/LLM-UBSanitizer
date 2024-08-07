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
 int /*<<< orphan*/  printk (char*,char const*,int,int) ; 

__attribute__((used)) static void
print_temp( const char *s, int temp )
{
	printk("%s%d.%d C", s ? s : "", temp>>8, (temp & 255)*10/256 );
}