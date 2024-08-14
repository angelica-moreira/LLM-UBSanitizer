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
typedef  int /*<<< orphan*/  wwn_t ;
struct bfa_fcs_rport_s {struct bfa_fcs_itnim_s* itnim; } ;
struct bfa_fcs_lport_s {int dummy; } ;
struct bfa_fcs_itnim_s {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON (int /*<<< orphan*/ ) ; 
 struct bfa_fcs_rport_s* bfa_fcs_rport_lookup (struct bfa_fcs_lport_s*,int /*<<< orphan*/ ) ; 

struct bfa_fcs_itnim_s *
bfa_fcs_itnim_lookup(struct bfa_fcs_lport_s *port, wwn_t rpwwn)
{
	struct bfa_fcs_rport_s *rport;
	rport = bfa_fcs_rport_lookup(port, rpwwn);

	if (!rport)
		return NULL;

	WARN_ON(rport->itnim == NULL);
	return rport->itnim;
}