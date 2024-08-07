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
typedef  int /*<<< orphan*/  vortex_t ;

/* Variables and functions */
 int /*<<< orphan*/  asDiamondCoefsLeftEq ; 
 int /*<<< orphan*/  asDiamondCoefsLeftXt ; 
 int /*<<< orphan*/  asDiamondCoefsRightEq ; 
 int /*<<< orphan*/  sDiamondKLeftEq ; 
 int /*<<< orphan*/  sDiamondKLeftXt ; 
 int /*<<< orphan*/  sDiamondKRightEq ; 
 int /*<<< orphan*/  sDiamondShiftLeftEq ; 
 int /*<<< orphan*/  sDiamondShiftLeftXt ; 
 int /*<<< orphan*/  sDiamondShiftRightEq ; 
 int /*<<< orphan*/  vortex_XtalkHw_SetDelay (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vortex_XtalkHw_SetLeftEQ (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vortex_XtalkHw_SetLeftXT (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vortex_XtalkHw_SetRightEQ (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vortex_XtalkHw_SetRightXT (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wDiamondLeftDelay ; 
 int /*<<< orphan*/  wDiamondRightDelay ; 

__attribute__((used)) static void vortex_XtalkHw_ProgramDiamondXtalk(vortex_t * vortex)
{

	//sDiamondKLeftEq,sDiamondKRightXt,asDiamondCoefsLeftEq
	vortex_XtalkHw_SetLeftEQ(vortex, sDiamondKLeftEq,
				 sDiamondShiftLeftEq, asDiamondCoefsLeftEq);
	vortex_XtalkHw_SetRightEQ(vortex, sDiamondKRightEq,
				  sDiamondShiftRightEq, asDiamondCoefsRightEq);
	vortex_XtalkHw_SetLeftXT(vortex, sDiamondKLeftXt,
				 sDiamondShiftLeftXt, asDiamondCoefsLeftXt);
	vortex_XtalkHw_SetRightXT(vortex, sDiamondKLeftXt,
				  sDiamondShiftLeftXt, asDiamondCoefsLeftXt);

	vortex_XtalkHw_SetDelay(vortex, wDiamondRightDelay, wDiamondLeftDelay);	// inlined
}