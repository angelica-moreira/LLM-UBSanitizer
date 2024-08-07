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
struct tep_event {int /*<<< orphan*/  name; int /*<<< orphan*/  system; } ;

/* Variables and functions */
 int events_id_cmp (void const*,void const*) ; 
 int strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int events_system_cmp(const void *a, const void *b)
{
	struct tep_event * const * ea = a;
	struct tep_event * const * eb = b;
	int res;

	res = strcmp((*ea)->system, (*eb)->system);
	if (res)
		return res;

	res = strcmp((*ea)->name, (*eb)->name);
	if (res)
		return res;

	return events_id_cmp(a, b);
}