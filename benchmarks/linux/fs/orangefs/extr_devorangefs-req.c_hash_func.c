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
typedef  int /*<<< orphan*/  __u64 ;

/* Variables and functions */
 int do_div (int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static int hash_func(__u64 tag, int table_size)
{
	return do_div(tag, (unsigned int)table_size);
}