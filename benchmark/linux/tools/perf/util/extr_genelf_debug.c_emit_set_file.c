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
struct buffer_ext {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DW_LNS_set_file ; 
 int /*<<< orphan*/  emit_opcode_unsigned (struct buffer_ext*,int /*<<< orphan*/ ,unsigned long) ; 

__attribute__((used)) static void emit_set_file(struct buffer_ext *be, unsigned long idx)
{
	emit_opcode_unsigned(be, DW_LNS_set_file, idx);
}