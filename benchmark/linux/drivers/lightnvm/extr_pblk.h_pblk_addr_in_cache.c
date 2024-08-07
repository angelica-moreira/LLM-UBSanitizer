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
struct TYPE_2__ {scalar_t__ is_cached; } ;
struct ppa_addr {scalar_t__ ppa; TYPE_1__ c; } ;

/* Variables and functions */
 scalar_t__ ADDR_EMPTY ; 

__attribute__((used)) static inline int pblk_addr_in_cache(struct ppa_addr ppa)
{
	return (ppa.ppa != ADDR_EMPTY && ppa.c.is_cached);
}