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
struct xa_state {int /*<<< orphan*/  xa_offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  xas_move_index (struct xa_state*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void xas_advance(struct xa_state *xas)
{
	xas->xa_offset++;
	xas_move_index(xas, xas->xa_offset);
}