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
struct label {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  FDT_END_NODE ; 
 int /*<<< orphan*/  bin_emit_cell (void*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void bin_emit_endnode(void *e, struct label *labels)
{
	bin_emit_cell(e, FDT_END_NODE);
}