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
struct db_dest {struct db_dest* pnext; } ;
struct au1000_private {struct db_dest* pDBfree; } ;

/* Variables and functions */

void au1000_ReleaseDB(struct au1000_private *aup, struct db_dest *pDB)
{
	struct db_dest *pDBfree = aup->pDBfree;
	if (pDBfree)
		pDBfree->pnext = pDB;
	aup->pDBfree = pDB;
}