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
struct syscalltbl {int /*<<< orphan*/  audit_machine; } ;

/* Variables and functions */
 int /*<<< orphan*/  audit_detect_machine () ; 
 struct syscalltbl* malloc (int) ; 

struct syscalltbl *syscalltbl__new(void)
{
	struct syscalltbl *tbl = malloc(sizeof(*tbl));
	if (tbl)
		tbl->audit_machine = audit_detect_machine();
	return tbl;
}