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
struct rpc_timeout {int to_initval; int to_retries; int to_increment; void* to_maxval; int to_exponential; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 int HZ ; 
 int NFS_DEF_TCP_RETRANS ; 
 int NFS_DEF_TCP_TIMEO ; 
 int NFS_DEF_UDP_RETRANS ; 
 int NFS_DEF_UDP_TIMEO ; 
 void* NFS_MAX_TCP_TIMEOUT ; 
 void* NFS_MAX_UDP_TIMEOUT ; 
 int NFS_UNSPEC_RETRANS ; 
 int NFS_UNSPEC_TIMEO ; 
#define  XPRT_TRANSPORT_RDMA 130 
#define  XPRT_TRANSPORT_TCP 129 
#define  XPRT_TRANSPORT_UDP 128 

void nfs_init_timeout_values(struct rpc_timeout *to, int proto,
				    int timeo, int retrans)
{
	to->to_initval = timeo * HZ / 10;
	to->to_retries = retrans;

	switch (proto) {
	case XPRT_TRANSPORT_TCP:
	case XPRT_TRANSPORT_RDMA:
		if (retrans == NFS_UNSPEC_RETRANS)
			to->to_retries = NFS_DEF_TCP_RETRANS;
		if (timeo == NFS_UNSPEC_TIMEO || to->to_initval == 0)
			to->to_initval = NFS_DEF_TCP_TIMEO * HZ / 10;
		if (to->to_initval > NFS_MAX_TCP_TIMEOUT)
			to->to_initval = NFS_MAX_TCP_TIMEOUT;
		to->to_increment = to->to_initval;
		to->to_maxval = to->to_initval + (to->to_increment * to->to_retries);
		if (to->to_maxval > NFS_MAX_TCP_TIMEOUT)
			to->to_maxval = NFS_MAX_TCP_TIMEOUT;
		if (to->to_maxval < to->to_initval)
			to->to_maxval = to->to_initval;
		to->to_exponential = 0;
		break;
	case XPRT_TRANSPORT_UDP:
		if (retrans == NFS_UNSPEC_RETRANS)
			to->to_retries = NFS_DEF_UDP_RETRANS;
		if (timeo == NFS_UNSPEC_TIMEO || to->to_initval == 0)
			to->to_initval = NFS_DEF_UDP_TIMEO * HZ / 10;
		if (to->to_initval > NFS_MAX_UDP_TIMEOUT)
			to->to_initval = NFS_MAX_UDP_TIMEOUT;
		to->to_maxval = NFS_MAX_UDP_TIMEOUT;
		to->to_exponential = 1;
		break;
	default:
		BUG();
	}
}