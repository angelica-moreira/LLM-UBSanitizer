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
typedef  scalar_t__ u64 ;
struct x86_emulate_ctxt {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ctxt_virt_addr_bits (struct x86_emulate_ctxt*) ; 
 scalar_t__ get_canonical (scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool emul_is_noncanonical_address(u64 la,
						struct x86_emulate_ctxt *ctxt)
{
#ifdef CONFIG_X86_64
	return get_canonical(la, ctxt_virt_addr_bits(ctxt)) != la;
#else
	return false;
#endif
}