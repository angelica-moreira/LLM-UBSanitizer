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
struct seq_file {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  private; } ;

/* Variables and functions */
 int /*<<< orphan*/  blkcg_policy_iolatency ; 
 int /*<<< orphan*/  blkcg_print_blkgs (struct seq_file*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  css_to_blkcg (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iolatency_prfill_limit ; 
 TYPE_1__* seq_cft (struct seq_file*) ; 
 int /*<<< orphan*/  seq_css (struct seq_file*) ; 

__attribute__((used)) static int iolatency_print_limit(struct seq_file *sf, void *v)
{
	blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)),
			  iolatency_prfill_limit,
			  &blkcg_policy_iolatency, seq_cft(sf)->private, false);
	return 0;
}