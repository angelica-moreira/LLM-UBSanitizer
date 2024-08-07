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
struct fc_rport_libfc_priv {unsigned int e_d_tov; } ;
struct fc_fcp_pkt {TYPE_1__* rport; } ;
struct TYPE_2__ {struct fc_rport_libfc_priv* dd_data; } ;

/* Variables and functions */
 unsigned int FC_DEF_E_D_TOV ; 
 unsigned int HZ ; 
 unsigned int msecs_to_jiffies (unsigned int) ; 

__attribute__((used)) static inline unsigned int get_fsp_rec_tov(struct fc_fcp_pkt *fsp)
{
	struct fc_rport_libfc_priv *rpriv = fsp->rport->dd_data;
	unsigned int e_d_tov = FC_DEF_E_D_TOV;

	if (rpriv && rpriv->e_d_tov > e_d_tov)
		e_d_tov = rpriv->e_d_tov;
	return msecs_to_jiffies(e_d_tov) + HZ;
}