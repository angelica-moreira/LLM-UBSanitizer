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

/* Variables and functions */
 int /*<<< orphan*/  RIC_FLUSH_ALL ; 
 int /*<<< orphan*/  _tlbie_lpid (unsigned int,int /*<<< orphan*/ ) ; 

void radix__flush_all_lpid(unsigned int lpid)
{
	_tlbie_lpid(lpid, RIC_FLUSH_ALL);
}