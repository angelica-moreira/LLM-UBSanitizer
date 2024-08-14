#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct aoedev {TYPE_1__* gd; } ;
struct TYPE_2__ {char const* disk_name; } ;

/* Variables and functions */
 char* kbasename (char const*) ; 
 int /*<<< orphan*/  strncmp (char*,char const*,size_t) ; 

__attribute__((used)) static int
user_req(char *s, size_t slen, struct aoedev *d)
{
	const char *p;
	size_t lim;

	if (!d->gd)
		return 0;
	p = kbasename(d->gd->disk_name);
	lim = sizeof(d->gd->disk_name);
	lim -= p - d->gd->disk_name;
	if (slen < lim)
		lim = slen;

	return !strncmp(s, p, lim);
}