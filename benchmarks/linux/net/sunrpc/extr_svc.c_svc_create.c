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
struct svc_serv_ops {int dummy; } ;
struct svc_serv {int dummy; } ;
struct svc_program {int dummy; } ;

/* Variables and functions */
 struct svc_serv* __svc_create (struct svc_program*,unsigned int,int,struct svc_serv_ops const*) ; 

struct svc_serv *
svc_create(struct svc_program *prog, unsigned int bufsize,
	   const struct svc_serv_ops *ops)
{
	return __svc_create(prog, bufsize, /*npools*/1, ops);
}