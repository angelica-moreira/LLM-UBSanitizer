#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ U16 ;
struct TYPE_4__ {int fastMode; scalar_t__ tableLog; } ;
struct TYPE_3__ {void* nbBits; void* symbol; scalar_t__ newState; } ;
typedef  TYPE_1__ FSE_decode_t ;
typedef  TYPE_2__ FSE_DTableHeader ;
typedef  int /*<<< orphan*/  FSE_DTable ;
typedef  void* BYTE ;

/* Variables and functions */
 size_t ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GENERIC ; 

size_t FSE_buildDTable_raw(FSE_DTable *dt, unsigned nbBits)
{
	void *ptr = dt;
	FSE_DTableHeader *const DTableH = (FSE_DTableHeader *)ptr;
	void *dPtr = dt + 1;
	FSE_decode_t *const dinfo = (FSE_decode_t *)dPtr;
	const unsigned tableSize = 1 << nbBits;
	const unsigned tableMask = tableSize - 1;
	const unsigned maxSV1 = tableMask + 1;
	unsigned s;

	/* Sanity checks */
	if (nbBits < 1)
		return ERROR(GENERIC); /* min size */

	/* Build Decoding Table */
	DTableH->tableLog = (U16)nbBits;
	DTableH->fastMode = 1;
	for (s = 0; s < maxSV1; s++) {
		dinfo[s].newState = 0;
		dinfo[s].symbol = (BYTE)s;
		dinfo[s].nbBits = (BYTE)nbBits;
	}

	return 0;
}