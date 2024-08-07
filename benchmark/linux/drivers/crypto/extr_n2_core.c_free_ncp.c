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
struct TYPE_2__ {struct n2_mau* ino_table; } ;
struct n2_mau {TYPE_1__ mau_info; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct n2_mau*) ; 

__attribute__((used)) static void free_ncp(struct n2_mau *mp)
{
	kfree(mp->mau_info.ino_table);
	mp->mau_info.ino_table = NULL;

	kfree(mp);
}