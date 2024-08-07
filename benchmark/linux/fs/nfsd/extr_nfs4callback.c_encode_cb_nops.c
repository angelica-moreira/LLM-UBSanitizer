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
struct nfs4_cb_compound_hdr {scalar_t__ nops; int /*<<< orphan*/ * nops_p; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 scalar_t__ NFS4_MAX_BACK_CHANNEL_OPS ; 
 int /*<<< orphan*/  cpu_to_be32 (scalar_t__) ; 

__attribute__((used)) static void encode_cb_nops(struct nfs4_cb_compound_hdr *hdr)
{
	BUG_ON(hdr->nops > NFS4_MAX_BACK_CHANNEL_OPS);
	*hdr->nops_p = cpu_to_be32(hdr->nops);
}