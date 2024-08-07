#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* m_pool_p ;
typedef  int /*<<< orphan*/  m_pool_ident_t ;
struct TYPE_5__ {TYPE_1__* next; } ;
struct TYPE_4__ {struct TYPE_4__* next; int /*<<< orphan*/  dev_dmat; } ;

/* Variables and functions */
 TYPE_2__ mp0 ; 
 int /*<<< orphan*/  sym_m_pool_match (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline m_pool_p ___get_dma_pool(m_pool_ident_t dev_dmat)
{
	m_pool_p mp;
	for (mp = mp0.next;
		mp && !sym_m_pool_match(mp->dev_dmat, dev_dmat);
			mp = mp->next);
	return mp;
}