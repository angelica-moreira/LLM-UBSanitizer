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
struct rs_control {int dummy; } ;
typedef  int /*<<< orphan*/  gfp_t ;

/* Variables and functions */
 struct rs_control* init_rs_internal (int,int,int /*<<< orphan*/ *,int,int,int,int /*<<< orphan*/ ) ; 

struct rs_control *init_rs_gfp(int symsize, int gfpoly, int fcr, int prim,
			       int nroots, gfp_t gfp)
{
	return init_rs_internal(symsize, gfpoly, NULL, fcr, prim, nroots, gfp);
}