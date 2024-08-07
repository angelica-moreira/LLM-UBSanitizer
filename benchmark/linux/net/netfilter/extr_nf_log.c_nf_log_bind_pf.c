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
typedef  size_t u_int8_t ;
struct nf_logger {int /*<<< orphan*/  name; } ;
struct TYPE_2__ {int /*<<< orphan*/ * nf_loggers; } ;
struct net {TYPE_1__ nf; } ;

/* Variables and functions */
 size_t ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int EINVAL ; 
 int ENOENT ; 
 int /*<<< orphan*/ * __find_logger (size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nf_log_mutex ; 
 int /*<<< orphan*/  rcu_assign_pointer (int /*<<< orphan*/ ,struct nf_logger const*) ; 

int nf_log_bind_pf(struct net *net, u_int8_t pf,
		   const struct nf_logger *logger)
{
	if (pf >= ARRAY_SIZE(net->nf.nf_loggers))
		return -EINVAL;
	mutex_lock(&nf_log_mutex);
	if (__find_logger(pf, logger->name) == NULL) {
		mutex_unlock(&nf_log_mutex);
		return -ENOENT;
	}
	rcu_assign_pointer(net->nf.nf_loggers[pf], logger);
	mutex_unlock(&nf_log_mutex);
	return 0;
}