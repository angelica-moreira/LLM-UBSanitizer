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
typedef  int /*<<< orphan*/  u32 ;
struct uasm_reloc {int dummy; } ;
struct uasm_label {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  uasm_move_labels (struct uasm_label*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,long) ; 
 int /*<<< orphan*/  uasm_move_relocs (struct uasm_reloc*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,long) ; 

void uasm_copy_handler(struct uasm_reloc *rel, struct uasm_label *lab,
				u32 *first, u32 *end, u32 *target)
{
	long off = (long)(target - first);

	memcpy(target, first, (end - first) * sizeof(u32));

	uasm_move_relocs(rel, first, end, off);
	uasm_move_labels(lab, first, end, off);
}