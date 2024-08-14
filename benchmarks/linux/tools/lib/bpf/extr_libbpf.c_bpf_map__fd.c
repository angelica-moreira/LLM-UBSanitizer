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
struct bpf_map {int fd; } ;

/* Variables and functions */
 int EINVAL ; 

int bpf_map__fd(const struct bpf_map *map)
{
	return map ? map->fd : -EINVAL;
}