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
struct dm_space_map {int (* root_size ) (struct dm_space_map*,size_t*) ;} ;

/* Variables and functions */
 int stub1 (struct dm_space_map*,size_t*) ; 

__attribute__((used)) static inline int dm_sm_root_size(struct dm_space_map *sm, size_t *result)
{
	return sm->root_size(sm, result);
}