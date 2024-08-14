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
struct bpf_prog {TYPE_1__* aux; } ;
struct TYPE_2__ {int func_cnt; int /*<<< orphan*/ * func; } ;

/* Variables and functions */
 int /*<<< orphan*/  bpf_prog_kallsyms_del (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void bpf_prog_kallsyms_del_subprogs(struct bpf_prog *fp)
{
	int i;

	for (i = 0; i < fp->aux->func_cnt; i++)
		bpf_prog_kallsyms_del(fp->aux->func[i]);
}