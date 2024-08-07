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
struct bpf_prog_array_item {int /*<<< orphan*/ * prog; } ;
struct bpf_prog_array {struct bpf_prog_array_item* items; } ;
struct TYPE_2__ {int /*<<< orphan*/  prog; } ;

/* Variables and functions */
 TYPE_1__ dummy_bpf_prog ; 

bool bpf_prog_array_is_empty(struct bpf_prog_array *array)
{
	struct bpf_prog_array_item *item;

	for (item = array->items; item->prog; item++)
		if (item->prog != &dummy_bpf_prog.prog)
			return false;
	return true;
}