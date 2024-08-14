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
typedef  scalar_t__ u32 ;
struct sym_hcb {int dummy; } ;

/* Variables and functions */
 int DEBUG_FLAGS ; 
 int DEBUG_TINY ; 
 int /*<<< orphan*/  HS_SEL_TIMEOUT ; 
 scalar_t__ INL (struct sym_hcb*,int /*<<< orphan*/ ) ; 
 scalar_t__ SCRIPTA_BA (struct sym_hcb*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nc_dsp ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  sym_recover_scsi_int (struct sym_hcb*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sym_start_reset (struct sym_hcb*) ; 
 int /*<<< orphan*/  wf_sel_done ; 

__attribute__((used)) static void sym_int_sto (struct sym_hcb *np)
{
	u32 dsp	= INL(np, nc_dsp);

	if (DEBUG_FLAGS & DEBUG_TINY) printf ("T");

	if (dsp == SCRIPTA_BA(np, wf_sel_done) + 8)
		sym_recover_scsi_int(np, HS_SEL_TIMEOUT);
	else
		sym_start_reset(np);
}