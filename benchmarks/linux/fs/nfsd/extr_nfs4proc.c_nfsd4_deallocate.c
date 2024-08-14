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
union nfsd4_op_u {int /*<<< orphan*/  deallocate; } ;
struct svc_rqst {int dummy; } ;
struct nfsd4_compound_state {int dummy; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int FALLOC_FL_KEEP_SIZE ; 
 int FALLOC_FL_PUNCH_HOLE ; 
 int /*<<< orphan*/  nfsd4_fallocate (struct svc_rqst*,struct nfsd4_compound_state*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static __be32
nfsd4_deallocate(struct svc_rqst *rqstp, struct nfsd4_compound_state *cstate,
		 union nfsd4_op_u *u)
{
	return nfsd4_fallocate(rqstp, cstate, &u->deallocate,
			       FALLOC_FL_PUNCH_HOLE | FALLOC_FL_KEEP_SIZE);
}