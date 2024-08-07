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
struct dm_exception {int new_chunk; } ;

/* Variables and functions */
 int DM_CHUNK_NUMBER_BITS ; 

__attribute__((used)) static inline unsigned dm_consecutive_chunk_count(struct dm_exception *e)
{
	return e->new_chunk >> DM_CHUNK_NUMBER_BITS;
}