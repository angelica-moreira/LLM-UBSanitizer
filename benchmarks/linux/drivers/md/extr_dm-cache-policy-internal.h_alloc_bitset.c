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
 size_t bitset_size_in_bytes (unsigned int) ; 
 unsigned long* vzalloc (size_t) ; 

__attribute__((used)) static inline unsigned long *alloc_bitset(unsigned nr_entries)
{
	size_t s = bitset_size_in_bytes(nr_entries);
	return vzalloc(s);
}