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
typedef  scalar_t__ fl_owner_t ;
typedef  int __u32 ;

/* Variables and functions */
 int cifs_lock_secret ; 
 int hash32_ptr (void const*) ; 

__attribute__((used)) static __u32
hash_lockowner(fl_owner_t owner)
{
	return cifs_lock_secret ^ hash32_ptr((const void *)owner);
}