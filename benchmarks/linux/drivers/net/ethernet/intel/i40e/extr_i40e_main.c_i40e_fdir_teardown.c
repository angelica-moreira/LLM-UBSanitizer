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
struct i40e_vsi {int dummy; } ;
struct i40e_pf {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  I40E_VSI_FDIR ; 
 int /*<<< orphan*/  i40e_fdir_filter_exit (struct i40e_pf*) ; 
 struct i40e_vsi* i40e_find_vsi_by_type (struct i40e_pf*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i40e_vsi_release (struct i40e_vsi*) ; 

__attribute__((used)) static void i40e_fdir_teardown(struct i40e_pf *pf)
{
	struct i40e_vsi *vsi;

	i40e_fdir_filter_exit(pf);
	vsi = i40e_find_vsi_by_type(pf, I40E_VSI_FDIR);
	if (vsi)
		i40e_vsi_release(vsi);
}