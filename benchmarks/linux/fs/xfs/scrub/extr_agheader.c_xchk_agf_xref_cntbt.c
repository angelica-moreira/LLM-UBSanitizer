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
typedef  scalar_t__ xfs_extlen_t ;
typedef  int /*<<< orphan*/  xfs_agblock_t ;
struct TYPE_2__ {int /*<<< orphan*/  agf_bp; int /*<<< orphan*/  cnt_cur; } ;
struct xfs_scrub {TYPE_1__ sa; } ;
struct xfs_agf {scalar_t__ agf_freeblks; int /*<<< orphan*/  agf_longest; } ;

/* Variables and functions */
 struct xfs_agf* XFS_BUF_TO_AGF (int /*<<< orphan*/ ) ; 
 scalar_t__ be32_to_cpu (int /*<<< orphan*/ ) ; 
 scalar_t__ cpu_to_be32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xchk_block_xref_set_corrupt (struct xfs_scrub*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xchk_should_check_xref (struct xfs_scrub*,int*,int /*<<< orphan*/ *) ; 
 int xfs_alloc_get_rec (int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__*,int*) ; 
 int xfs_alloc_lookup_le (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,int*) ; 

__attribute__((used)) static inline void
xchk_agf_xref_cntbt(
	struct xfs_scrub	*sc)
{
	struct xfs_agf		*agf = XFS_BUF_TO_AGF(sc->sa.agf_bp);
	xfs_agblock_t		agbno;
	xfs_extlen_t		blocks;
	int			have;
	int			error;

	if (!sc->sa.cnt_cur)
		return;

	/* Any freespace at all? */
	error = xfs_alloc_lookup_le(sc->sa.cnt_cur, 0, -1U, &have);
	if (!xchk_should_check_xref(sc, &error, &sc->sa.cnt_cur))
		return;
	if (!have) {
		if (agf->agf_freeblks != cpu_to_be32(0))
			xchk_block_xref_set_corrupt(sc, sc->sa.agf_bp);
		return;
	}

	/* Check agf_longest */
	error = xfs_alloc_get_rec(sc->sa.cnt_cur, &agbno, &blocks, &have);
	if (!xchk_should_check_xref(sc, &error, &sc->sa.cnt_cur))
		return;
	if (!have || blocks != be32_to_cpu(agf->agf_longest))
		xchk_block_xref_set_corrupt(sc, sc->sa.agf_bp);
}