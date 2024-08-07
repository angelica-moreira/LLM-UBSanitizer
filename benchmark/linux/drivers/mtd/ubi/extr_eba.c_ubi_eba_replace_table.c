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
struct ubi_volume {struct ubi_eba_table* eba_tbl; } ;
struct ubi_eba_table {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ubi_eba_destroy_table (struct ubi_eba_table*) ; 

void ubi_eba_replace_table(struct ubi_volume *vol, struct ubi_eba_table *tbl)
{
	ubi_eba_destroy_table(vol->eba_tbl);
	vol->eba_tbl = tbl;
}