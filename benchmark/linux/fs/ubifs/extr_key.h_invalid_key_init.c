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
union ubifs_key {int* u32; } ;
struct ubifs_info {int dummy; } ;

/* Variables and functions */
 int UBIFS_INVALID_KEY ; 

__attribute__((used)) static inline void invalid_key_init(const struct ubifs_info *c,
				    union ubifs_key *key)
{
	key->u32[0] = 0xDEADBEAF;
	key->u32[1] = UBIFS_INVALID_KEY;
}