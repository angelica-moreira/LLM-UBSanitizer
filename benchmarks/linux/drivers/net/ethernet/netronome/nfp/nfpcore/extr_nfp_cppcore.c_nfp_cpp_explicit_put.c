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
struct nfp_cpp_explicit {int dummy; } ;

/* Variables and functions */
 int NFP_EXPL_OP (int /*<<< orphan*/ ,struct nfp_cpp_explicit*,void const*,size_t) ; 
 int /*<<< orphan*/  explicit_put ; 

int nfp_cpp_explicit_put(struct nfp_cpp_explicit *expl,
			 const void *buff, size_t len)
{
	return NFP_EXPL_OP(explicit_put, expl, buff, len);
}