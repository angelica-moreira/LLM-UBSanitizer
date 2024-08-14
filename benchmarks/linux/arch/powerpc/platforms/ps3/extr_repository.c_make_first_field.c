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
typedef  int u64 ;

/* Variables and functions */
 int PS3_VENDOR_ID_NONE ; 
 int /*<<< orphan*/  strncpy (char*,char const*,int) ; 

__attribute__((used)) static u64 make_first_field(const char *text, u64 index)
{
	u64 n;

	strncpy((char *)&n, text, 8);
	return PS3_VENDOR_ID_NONE + (n >> 32) + index;
}