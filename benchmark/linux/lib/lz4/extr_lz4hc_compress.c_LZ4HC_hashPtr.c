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
typedef  int /*<<< orphan*/  U32 ;

/* Variables and functions */
 int /*<<< orphan*/  HASH_FUNCTION (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LZ4_read32 (void const*) ; 

__attribute__((used)) static U32 LZ4HC_hashPtr(const void *ptr)
{
	return HASH_FUNCTION(LZ4_read32(ptr));
}