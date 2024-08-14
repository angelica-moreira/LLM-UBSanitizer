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
struct sock_filter {int dummy; } ;
struct TYPE_3__ {unsigned int len; struct sock_filter* insns; } ;
struct TYPE_4__ {TYPE_1__ ptr; } ;
struct bpf_test {TYPE_2__ u; } ;

/* Variables and functions */
 int BPF_ABS ; 
 int BPF_B ; 
 int BPF_K ; 
 int BPF_LD ; 
 unsigned int BPF_MAXINSNS ; 
 int BPF_RET ; 
 int BPF_W ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int SKF_AD_CPU ; 
 int SKF_AD_OFF ; 
 struct sock_filter __BPF_STMT (int,int) ; 
 struct sock_filter* kmalloc_array (unsigned int,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int bpf_fill_ld_abs_get_processor_id(struct bpf_test *self)
{
	unsigned int len = BPF_MAXINSNS;
	struct sock_filter *insn;
	int i;

	insn = kmalloc_array(len, sizeof(*insn), GFP_KERNEL);
	if (!insn)
		return -ENOMEM;

	for (i = 0; i < len - 1; i += 2) {
		insn[i] = __BPF_STMT(BPF_LD | BPF_B | BPF_ABS, 0);
		insn[i + 1] = __BPF_STMT(BPF_LD | BPF_W | BPF_ABS,
					 SKF_AD_OFF + SKF_AD_CPU);
	}

	insn[len - 1] = __BPF_STMT(BPF_RET | BPF_K, 0xbee);

	self->u.ptr.insns = insn;
	self->u.ptr.len = len;

	return 0;
}