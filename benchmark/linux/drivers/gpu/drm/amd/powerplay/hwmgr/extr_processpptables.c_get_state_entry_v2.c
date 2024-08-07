#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ ULONG ;
struct TYPE_6__ {int /*<<< orphan*/  ucNumDPMLevels; } ;
struct TYPE_5__ {scalar_t__ ucNumEntries; TYPE_2__* states; } ;
typedef  TYPE_1__ StateArray ;
typedef  TYPE_2__ ATOM_PPLIB_STATE_V2 ;

/* Variables and functions */
 scalar_t__ size_of_entry_v2 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static const ATOM_PPLIB_STATE_V2 *get_state_entry_v2(
					const StateArray * pstate_arrays,
							 ULONG entry_index)
{
	ULONG i;
	const ATOM_PPLIB_STATE_V2 *pstate;

	pstate = pstate_arrays->states;
	if (entry_index <= pstate_arrays->ucNumEntries) {
		for (i = 0; i < entry_index; i++)
			pstate = (ATOM_PPLIB_STATE_V2 *)(
						  (unsigned long)pstate +
			     size_of_entry_v2(pstate->ucNumDPMLevels));
	}
	return pstate;
}