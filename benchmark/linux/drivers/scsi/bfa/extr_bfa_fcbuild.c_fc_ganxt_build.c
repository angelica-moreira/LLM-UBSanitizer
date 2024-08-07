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
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct fchs_s {int dummy; } ;
struct fcgs_ganxt_req_s {int /*<<< orphan*/  port_id; } ;
struct ct_hdr_s {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  FC_NAME_SERVER ; 
 int /*<<< orphan*/  GS_GA_NXT ; 
 int /*<<< orphan*/  bfa_hton3b (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fc_gs_cthdr_build (struct ct_hdr_s*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fc_gs_fchdr_build (struct fchs_s*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct fcgs_ganxt_req_s*,int /*<<< orphan*/ ,int) ; 

u16
fc_ganxt_build(struct fchs_s *fchs, void *pyld, u32 s_id, u32 port_id)
{
	struct ct_hdr_s *cthdr = (struct ct_hdr_s *) pyld;
	struct fcgs_ganxt_req_s *ganxt = (struct fcgs_ganxt_req_s *)(cthdr + 1);
	u32        d_id = bfa_hton3b(FC_NAME_SERVER);

	fc_gs_fchdr_build(fchs, d_id, s_id, 0);
	fc_gs_cthdr_build(cthdr, s_id, GS_GA_NXT);

	memset(ganxt, 0, sizeof(struct fcgs_ganxt_req_s));
	ganxt->port_id = port_id;

	return sizeof(struct ct_hdr_s) + sizeof(struct fcgs_ganxt_req_s);
}