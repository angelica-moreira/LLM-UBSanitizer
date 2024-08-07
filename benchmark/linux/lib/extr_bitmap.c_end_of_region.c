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
 scalar_t__ __end_of_region (char) ; 
 scalar_t__ end_of_str (char) ; 

__attribute__((used)) static inline bool end_of_region(char c)
{
	return __end_of_region(c) || end_of_str(c);
}