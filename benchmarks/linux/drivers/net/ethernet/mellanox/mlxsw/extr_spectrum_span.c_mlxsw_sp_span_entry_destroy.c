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
struct mlxsw_sp_span_entry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlxsw_sp_span_entry_deconfigure (struct mlxsw_sp_span_entry*) ; 

__attribute__((used)) static void mlxsw_sp_span_entry_destroy(struct mlxsw_sp_span_entry *span_entry)
{
	mlxsw_sp_span_entry_deconfigure(span_entry);
}