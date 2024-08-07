#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int* gregs; } ;
struct TYPE_4__ {TYPE_1__ uc_mcontext; } ;
typedef  TYPE_2__ ucontext_t ;
typedef  int /*<<< orphan*/  siginfo_t ;

/* Variables and functions */
 size_t REG_EFL ; 
 size_t REG_IP ; 
 int X86_EFLAGS_RF ; 
 int /*<<< orphan*/  printf (char*,unsigned long,int) ; 

__attribute__((used)) static void sigtrap(int sig, siginfo_t *si, void *ctx_void)
{
	ucontext_t *ctx = ctx_void;

	printf("\tGot SIGTRAP with RIP=%lx, EFLAGS.RF=%d\n",
	       (unsigned long)ctx->uc_mcontext.gregs[REG_IP],
	       !!(ctx->uc_mcontext.gregs[REG_EFL] & X86_EFLAGS_RF));
}