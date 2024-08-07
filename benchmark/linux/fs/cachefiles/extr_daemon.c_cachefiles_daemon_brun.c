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
struct cachefiles_cache {unsigned long bcull_percent; unsigned long brun_percent; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  _enter (char*,char*) ; 
 int cachefiles_daemon_range_error (struct cachefiles_cache*,char*) ; 
 unsigned long simple_strtoul (char*,char**,int) ; 

__attribute__((used)) static int cachefiles_daemon_brun(struct cachefiles_cache *cache, char *args)
{
	unsigned long brun;

	_enter(",%s", args);

	if (!*args)
		return -EINVAL;

	brun = simple_strtoul(args, &args, 10);
	if (args[0] != '%' || args[1] != '\0')
		return -EINVAL;

	if (brun <= cache->bcull_percent || brun >= 100)
		return cachefiles_daemon_range_error(cache, args);

	cache->brun_percent = brun;
	return 0;
}