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
struct string_list {scalar_t__ tag; struct string_list* next; int /*<<< orphan*/  string; } ;

/* Variables and functions */
 scalar_t__ strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int equal_list(struct string_list *a, struct string_list *b)
{
	while (a && b) {
		if (a->tag != b->tag || strcmp(a->string, b->string))
			return 0;
		a = a->next;
		b = b->next;
	}

	return !a && !b;
}