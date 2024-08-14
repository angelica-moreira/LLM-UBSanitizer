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
struct perf_cpu_map {int dummy; } ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_map__snprint (struct perf_cpu_map*,char*,int) ; 
 struct perf_cpu_map* perf_cpu_map__new (char const*) ; 
 int /*<<< orphan*/  strcmp (char*,char const*) ; 

__attribute__((used)) static int cpu_map_print(const char *str)
{
	struct perf_cpu_map *map = perf_cpu_map__new(str);
	char buf[100];

	if (!map)
		return -1;

	cpu_map__snprint(map, buf, sizeof(buf));
	return !strcmp(buf, str);
}