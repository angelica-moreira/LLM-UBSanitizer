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
struct gf128mul_64k {struct gf128mul_64k** t; } ;

/* Variables and functions */
 int /*<<< orphan*/  kzfree (struct gf128mul_64k*) ; 

void gf128mul_free_64k(struct gf128mul_64k *t)
{
	int i;

	for (i = 0; i < 16; i++)
		kzfree(t->t[i]);
	kzfree(t);
}